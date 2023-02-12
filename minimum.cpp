#include <iostream>

#include "expression.h"
#include "minimum.h"
#include "binaryexpression.h"

Minimum::Minimum(Expression* left, Expression* right) : BinaryExpression(left, right) {
}

double Minimum::evaluate() {
    return fmin(left->calculate(), right->calculate());
}