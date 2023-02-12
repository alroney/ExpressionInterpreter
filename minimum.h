#include "binaryexpression.h"

class Minimum : public BinaryExpression {
public:
    Minimum(Expression* left, Expression* right);
    virtual double calculate();
};