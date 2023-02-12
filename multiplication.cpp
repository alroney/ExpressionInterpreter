#include <iostream>

#include "multiplication.h"
#include "expression.h"

Multiplication::Multiplication(Expression* left, Expression* right) : SubExpression(left, right)
{
}

double Multiplication::evaluate()
{
    return left->evaluate() * right->evaluate();
}