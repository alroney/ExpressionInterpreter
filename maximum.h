#include "binaryexpression.h"

class Maximum : public BinaryExpression {
public:
    Maximum(Expression* left, Expression* right);
    int evaluate();
};