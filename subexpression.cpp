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
    Expression* trueExpr;
    Expression* falseExpr;
    char operation, paren, question, colon, semicolon, currentChar;


    left = Operand::parse(in);
    in >> ws >> operation >> ws;
    right = Operand::parse(in);
    in >> ws >> question >> ws;

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
    cout << "\tquestion: " << question << endl;

    

    if (question != '?') {
        cout << "\tA binary expression was found: " << endl;
        cout << "\t\tLeft Expression: " << left->evaluate() << endl;
        cout << "\t\tRight Expression: " << right->evaluate() << endl;
        cout << "\t\tOperation: " << operation << endl;
        return new BinaryExpression(left, binary_op, right);//First Binary Expression
    }

    if ((operation == '<' || operation == '>' || operation == '_' ) && question == '?') {
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
    
    return 0;
    
}
        