#include <iostream>

#include "expression.h"
#include "average.h"

Average::Average(Expression* left, Expression* right) : SubExpression(left, right) {
}

double Average::evaluate() {
    return (left->evaluate() + right->evaluate()) / 2;
}