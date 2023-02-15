/*
* Name: Andrew Roney
* Date: 2/14/2023
* Project: Project 2
* Description: This file contains the body of the functions contained in The SubExpression class, which includes
*   the constructor that initializes the left and right subexpressions and the static function parse that
*   parses the subexpression. This is where the binary, ternary and quaternary expressions are parsed. 
*/

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
#include "unaryexpression.h"
#include "binaryexpression.h"
#include "ternaryexpression.h"
#include "quaternaryexpression.h"
#include "subexpression.h"
#include "operand.h"


//Function: this finction initializes a single subexpression
SubExpression::SubExpression(Expression* left) {
    this->left = left;
}

//Function: this function initializes the left and right subexpressions of the expression.
SubExpression::SubExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

//Function: this function parses the subexpression and returns it. It also determines if the expression is binary, ternary or quaternary
Expression* SubExpression::parse(stringstream& in) {
    Expression* left;
    Expression* right;
    //Unary Expression Variables
    UnaryExpression* lUnary;
    UnaryExpression* rUnary;
    //Ternary Expression Variables
    Expression* trueExpr;
    Expression* falseExpr;
    //Quaternary Expression Variables
    Expression* belowExpr;
    Expression* sameExpr;
    Expression* aboveExpr;

    char nextCheck, operation, paren, expr_decision, question, colon, semicolon;
    char tilde = ' ';
    bool isNeg = false;

    nextCheck = in.peek();
    if (nextCheck == '~') {//if the next character is a tilde then the next subexpression is negative
        in >> tilde;
        isNeg = true;
    }

    left = Operand::parse(in);//parse the left subexpression
    
    //region - LEFT SUBEXPRESSION - check the left subexpression for a unary expression
        nextCheck = in.peek();//check the next character in the stream
        
        if (nextCheck == ')') {//if the next character is a closing parenthesis then the subexpression is complete and the unary expression is returned on it own
            return new UnaryExpression(left, isNeg);//return the unary expression
        }

        else {
            lUnary = new UnaryExpression(left, isNeg);
            left = lUnary;
            in >> ws >> operation;
        }
    //endregion


    //region - BINARY OPERATOR - determine the binary operator
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
    //endregion

    in >> ws;//Consume the whitespace if there is any

    nextCheck = in.peek();//check the next character in the stream
    if (nextCheck == '~') {//if the next character is a tilde then the next subexpression is negative
        in >> tilde;//consume the tilde
        isNeg = true;//set the isNeg flag to true
    }
    
    right = Operand::parse(in);
    //cout << "\n\tright: " << right->evaluate() << endl;

    //region - RIGHT SUBEXPRESSION - check the right subexpression for a unary expression
        //The right expression cannot be considered on its own because it is part of a binary expression. Therefore, no need to check for a closing parenthesis
        rUnary = new UnaryExpression(right, isNeg);
        right = rUnary;
    //endregion
    
    in >> ws >> expr_decision >> ws;//check the next character in the stream to see if it is a question mark or a hash or none of the above    

    //region - BINARY EXPRESSION - return the binary expression only
        if (expr_decision != '?' && expr_decision != '#') {//If the expression decision is not a question mark or a hash then it is a binary expression
            return new BinaryExpression(left, binary_op, right);//First Binary Expression
        }
    //endregion

    //region - TERNARY EXPRESSION - return the ternary expression with the binary expression as the condition
        if ((operation == '<' || operation == '>' || operation == '_' ) && expr_decision == '?') {//If the operation is a comparison and the expression decision is a question mark then it is a ternary expression
            trueExpr = Operand::parse(in);
            in >> ws >> colon >> ws;
            falseExpr = Operand::parse(in);
            in >> ws >> semicolon >> ws;

            return new TernaryExpression(new BinaryExpression(left, binary_op, right), trueExpr, falseExpr);//Return the ternary expression with the binary expression as the condition
        }
    //endregion

    //region - QUATERNARY EXPRESSION - return the quaternary expression with the binary expression as the condition
        if (expr_decision == '#' && (operation != '<' || operation != '>' || operation != '_')){//If the operation is not a comparison and the expression decision is a hash then it is a quaternary expression
            
            belowExpr = Operand::parse(in);//Parse the below expression
            in >> ws >> colon >> ws;
            sameExpr = Operand::parse(in);//Parse the same expression
            in >> ws >> colon >> ws;
            aboveExpr = Operand::parse(in);//Parse the above expression
            in >> ws >> semicolon >> ws;
            return new QuaternaryExpression(new BinaryExpression(left, binary_op, right), belowExpr, sameExpr, aboveExpr);//Return the ternary expression with the binary expression as the condition
        }
    //endregion
    
    return 0;
    
}
        