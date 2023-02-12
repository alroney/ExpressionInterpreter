#include "division.h"

Division::Division(Expression* left, Expression* right) : SubExpression(left, right)
{
    this->left = left;
    this->right = right;
}

double Division::evaluate()
{
    return left->evaluate() / right->evaluate();
}