/*
* Name: Andrew Roney
* Date: 2/14/2023
* Project: Project 2
* Description: This file contains the QuaternaryExpression class, which is a subclass of Expression. It contains
*   a constructor that takes four parameters: a pointer to an Expression object, a pointer to another
*   Expression object, a pointer to a third Expression object, and a pointer to a fourth Expression object.
*   It also contains the body of the evaluate function, which returns the result of the operation on the
*   three subexpressions. The evaluate function is implemented as a series of if statements that perform
*   the operation on the three subexpressions and returns the result.
*/

class QuaternaryExpression : public Expression {
public:
    QuaternaryExpression(Expression* condition, Expression* belowExpr, Expression* sameExpr, Expression* aboveExpr);
    double evaluate();
    
private://private variables for the class QuaternaryExpression. These variables are pointers to Expression objects
    Expression* condition;
    Expression* belowExpr;
    Expression* sameExpr;
    Expression* aboveExpr;
};