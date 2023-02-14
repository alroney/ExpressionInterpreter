/*
* Name: Andrew Roney
* Date: 2/14/2023
* Project: Project 2
* Description: This file contains the UnaryExpression class, which is a subclass of Expression. It contains
*   a constructor that takes two parameters: a pointer to an Expression object and a boolean value. 
*/

class UnaryExpression : public Expression {
public:
    UnaryExpression(Expression* expr, bool isNeg);

    double evaluate();
private:
    Expression* expr;
    bool isNeg;
};