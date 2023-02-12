// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the class definition of the SubExpression class, which is a subclass of Expression.
// Because it does not implement the abstract function evalauate, it is an abstract class. SubExpression
// objects are represented with the left and right subexpressions. The body of its constructor and the
// static (class) function parse are defined in subexpression.cpp. 

class SubExpression: public Expression {
public:
    SubExpression(Expression* left);//added
    SubExpression(Expression* left, Expression* right);
    SubExpression(Expression* left, Expression* middle1, Expression* right);//added
    SubExpression(Expression* left, Expression* middle1, Expression* middle2, Expression* right);//added
    static Expression* parse(stringstream& in);
protected: 
    Expression* left;
    Expression* right;
    Expression* middle1;//added
    Expression* middle2;//added
};    