// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SubExpression class, which includes
// the constructor that initializes the left and right subexpressions and the static function parse
// parses the subexpression. Addition and subtraction are the two operators that are implemented.

#include <iostream>
#include <sstream>
#include <regex>
#include <string>
using namespace std;

#include "expression.h"
#include "binaryexpression.h"
#include "ternaryexpression.h"
#include "quaternaryexpression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"



SubExpression::SubExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse(stringstream& in) {
    Expression* left;
    Expression* right;
    //Ternary Expression Variables
    Expression* trueExpr;
    Expression* falseExpr;
    //Quaternary Expression Variables
    Expression* belowExpr;
    Expression* sameExpr;
    Expression* aboveExpr;

    char operation, paren, expr_decision, question, colon, semicolon;


    left = Operand::parse(in);
    in >> ws >> operation >> ws;
    right = Operand::parse(in);
    in >> ws >> expr_decision >> ws;

    int count = 0;
    cout << "\n\toperation: " << operation << endl;

    BinaryOperator binary_op = NONE;
    switch (operation) {
        case '+':
            binary_op = ADD; break;
        case '-':
            binary_op = SUBTRACT; break;
        case '*':
            binary_op = MULTIPLY; break;
        case '/':
            binary_op = DIVIDE; break;
        case '%':
            binary_op = MODULO; break;
        case '^':
            binary_op = POWER; break;
        case '<':
            binary_op = LESS_THAN; break;
        case '>':
            binary_op = GREATER_THAN; break;
        case '_':
            binary_op = UNDERSCORE; break;
    }
    cout << "\tleft: " << left->evaluate() << endl;
    cout << "\tright: " << right->evaluate() << endl;
    cout << "expr_decision: " << expr_decision << endl;

    
    //region - BINARY EXPRESSION - return the binary expression only
    if (expr_decision != '?' && expr_decision != '#') {
        cout << "\tA binary expression was found: " << endl;
        cout << "\t\tLeft Expression: " << left->evaluate() << endl;
        cout << "\t\tRight Expression: " << right->evaluate() << endl;
        cout << "\t\tOperation: " << operation << endl;
        return new BinaryExpression(left, binary_op, right);//First Binary Expression
    }
    //endregion

    //region - TERNARY EXPRESSION - return the ternary expression with the binary expression as the condition
    if ((operation == '<' || operation == '>' || operation == '_' ) && expr_decision == '?') {//If the operation is a comparison and the expression decision is a question mark then it is a ternary expression
        cout << "\tA ternary expression was found: " << endl;
        //After the question mark, there should be a true expression then a colon, then a false expression
        trueExpr = Operand::parse(in);
        in >> ws >> colon >> ws;
        falseExpr = Operand::parse(in);
        in >> ws >> semicolon >> ws;
        cout << "\t\tTrue Expression: " << trueExpr->evaluate() << endl;
        cout << "\t\tFalse Expression: " << falseExpr->evaluate() << endl;
        return new TernaryExpression(new BinaryExpression(left, binary_op, right), trueExpr, falseExpr);//Return the ternary expression with the binary expression as the condition
    }
    //endregion

    //region - QUATERNARY EXPRESSION - return the quaternary expression with the binary expression as the condition
    if (expr_decision == '#' && (operation != '<' || operation != '>' || operation != '_')){//If the operation is not a comparison and the expression decision is a hash then it is a quaternary expression
        cout << "\tA quaternary expression was found: " << endl;
        //After the '#' symbol, there should be a true expression then a colon, then a false expression
        belowExpr = Operand::parse(in);
        in >> ws >> colon >> ws;
        sameExpr = Operand::parse(in);
        in >> ws >> colon >> ws;
        aboveExpr = Operand::parse(in);
        in >> ws >> semicolon >> ws;
        cout << "\t\tBelow Expression: " << belowExpr->evaluate() << endl;
        cout << "\t\tSame Expression: " << sameExpr->evaluate() << endl;
        cout << "\t\tAbove Expression: " << aboveExpr->evaluate() << endl;
        return new QuaternaryExpression(new BinaryExpression(left, binary_op, right), belowExpr, sameExpr, aboveExpr);//Return the ternary expression with the binary expression as the condition
    }
    
    return 0;
    
}
        