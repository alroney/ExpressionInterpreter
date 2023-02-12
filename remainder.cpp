#include <iostream>

#include "expression.h"
#include "remainder.h"

Remainder::Remainder(Expression* left, Expression* right) : SubExpression(left, right) {
}

double Remainder::evaluate() {
    return (int)left->evaluate() % (int)right->evaluate();
}