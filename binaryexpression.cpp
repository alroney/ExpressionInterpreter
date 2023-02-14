/*
* Name: Andrew Roney
* Date: 2/14/2023
* Project: Project 2
* Description: This file contains the implementation of the BinaryExpression class, which is a subclass of Expression. It contains
*   a constructor that takes three parameters: a pointer to an Expression object, a BinaryOperator, and a
*   pointer to another Expression object. It also contains the body of the evaluate function, which returns
*   the result of the operation on the two subexpressions. The evaluate function is implemented as a switch
*   statement that performs the operation on the two subexpressions and returns the result. The switch
*   statement is based on the value of the BinaryOperator parameter. The evaluate function is implemented as a switch
*   statement that performs the operation on the two subexpressions and returns the result.
*/

#include "expression.h"
#include "binaryexpression.h"

BinaryExpression::BinaryExpression(Expression* left, BinaryOperator op, Expression* right) {
        this->left = left;
        this->op = op;
        this->right = right;
}

double BinaryExpression::evaluate() {
    switch (op) {
        case ADD:
            return left->evaluate() + right->evaluate();
        case SUBTRACT:
            return left->evaluate() - right->evaluate();
        case MULTIPLY:
            return left->evaluate() * right->evaluate();
        case DIVIDE:
            return left->evaluate() / right->evaluate();
        case MODULO:
            return (int)left->evaluate() % (int)right->evaluate();
        case POWER:
            return pow(left->evaluate(), right->evaluate());
        case LESS_THAN:
            return left->evaluate() < right->evaluate();
        case GREATER_THAN:
            return left->evaluate() > right->evaluate();
        case UNDERSCORE:
            return left->evaluate() == right->evaluate();
        default:
            return 0;
    }
}