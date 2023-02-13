// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SubExpression class, which includes
// the constructor that initializes the left and right subexpressions and the static function parse
// parses the subexpression. Addition and subtraction are the two operators that are implemented.

#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "binaryexpression.h"
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
    char operation, paren;

    left = Operand::parse(in);
    in >> ws >> operation;
    right = Operand::parse(in);
    in >> ws >> paren;

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
    return new BinaryExpression(left, binary_op, right);
}
        