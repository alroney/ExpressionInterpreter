/*
* Name: Andrew Roney
* Date: 2/14/2023
* Project: Project 2
* Description: This file contains the BinaryOperator enum, which is used in the BinaryExpression class. It
*   contains the values ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULO, POWER, LESS_THAN, GREATER_THAN, and
*   UNDERSCORE. The enum is used in the BinaryExpression class to determine which operation to perform on
*   the two subexpressions. The enum is implemented as a switch statement in the evaluate function of the
*   BinaryExpression class.
*/

enum BinaryOperator {ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULO, POWER, LESS_THAN, GREATER_THAN, UNDERSCORE, NONE};