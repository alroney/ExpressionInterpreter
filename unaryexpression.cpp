#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

#include "expression.h"
#include "unaryexpression.h"
#include "operand.h"

UnaryExpression::UnaryExpression(Expression* expression) {
    this->expression = expression;
}

double UnaryExpression::evaluate() {
    return -expression->evaluate();
}
