#include "binaryexpression.h"

BinaryExpression::BinaryExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

BinaryExpression::~BinaryExpression() {
    delete left;
    delete right;
}