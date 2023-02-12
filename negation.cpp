#include "negation.h"

Negation::Negation(Expression* operand) {
    this->operand = operand;
}

double Negation::evaluate() {
    return -1 * operand->evaluate();
}