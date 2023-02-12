#include <iostream>
#include <cmath>

#include "expression.h"
#include "exponentiation.h"

Exponentiation::Exponentiation(Expression* left, Expression* right) : SubExpression(left, right) {
}

double Exponentiation::evaluate() {
    return pow(left->evaluate(), right->evaluate());
}