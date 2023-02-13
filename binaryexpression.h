
#include <cmath>
#include "binaryoperator.h"


class BinaryExpression: public Expression {
public:
    BinaryExpression(Expression* left, BinaryOperator op, Expression* right) {
        this->left = left;
        this->op = op;
        this->right = right;
    }
    double evaluate() {
        switch (op) {
            case ADD:
                return left->evaluate() + right->evaluate();
            case SUBTRACT:
                return left->evaluate() - right->evaluate();
            case MULTIPLY:
                return left->evaluate() * right->evaluate();
            case DIVIDE:
                return left->evaluate() / right->evaluate();
            case MODULO:
                return (int)left->evaluate() % (int)right->evaluate();
            case POWER:
                return pow(left->evaluate(), right->evaluate());
            case LESS_THAN:
                return left->evaluate() < right->evaluate();
            case GREATER_THAN:
                return left->evaluate() > right->evaluate();
            case UNDERSCORE:
                return left->evaluate() == right->evaluate();
            default:
                return 0;
        }
    }

private:
    Expression* left;
    BinaryOperator op;
    Expression* right;
};