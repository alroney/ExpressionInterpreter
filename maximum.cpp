#include "maximum.h"

Maximum::Maximum(Expression* left, Expression* right) : BinaryExpression(left, right) {
}

int Maximum::calculate() {
    return left->calculate() > right->calculate() ? left->calculate() : right->calculate();
}