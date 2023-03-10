/*
* Name: Andrew Roney
* Date: 2/14/2023
* Project: Project 2
* Description: This file contains the BinaryExpression class, which is a subclass of Expression. It contains
*   a constructor that takes three parameters: a pointer to an Expression object, a BinaryOperator, and a
*   pointer to another Expression object. It also contains the body of the evaluate function, which returns
*   the result of the operation on the two subexpressions.
*/


#include <cmath>
#include "binaryoperator.h"


class BinaryExpression: public Expression {
public:
    BinaryExpression(Expression* left, BinaryOperator op, Expression* right);
    double evaluate();

private:
    Expression* left;
    BinaryOperator op;
    Expression* right;
};