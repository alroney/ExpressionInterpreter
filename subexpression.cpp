// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SubExpression class, which includes
// the constructor that initializes the left and right subexpressions and the static function parse
// parses the subexpression. Addition and subtraction are the two operators that are implemented.

#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "negate.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "modulo.h"
#include "power.h"
#include "lessThan.h"
#include "greaterThan.h"

SubExpression::SubExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse(stringstream& in) {
    Expression* left;
    Expression* right;
    char operation, paren;
    
    left = Operand::parse(in);
    in >> operation;
    if (operation == '~') {
        return new Negate(left);
    }
    else{
        right = Operand::parse(in);
        in >> paren;
        switch (operation) {
            case '+':
                return new Plus(left, right);
            case '-':
                return new Minus(left, right);
            //region - ADDED - added by me
            case '*':
                return new Times(left, right);
            case '/':
                return new Divide(left, right);
            case '%':
                return new Modulo(left, right);
            case '^':
                return new Power(left, right);
            case '<':
                return new LessThan(left, right);
            case '>':
                return new GreaterThan(left, right);
            //endregion
        }
    }
    return 0;
}
        