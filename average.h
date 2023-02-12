#include "subexpression.h"

class Average : public SubExpression {
public:
    Average(Expression* left, Expression* right);
    double evaluate();
};