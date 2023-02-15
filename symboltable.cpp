/*
* Name: Andrew Roney
* Date: 2/14/2023
* Project: Project 2
* Description: This file contains the SymbolTable class, which contains a vector of Symbol objects. It contains
*   a constructor that takes no parameters, an insert function that takes a variable name and its value as
*   parameters and inserts them into the symbol table, a lookUp function that takes a variable name as a
*   parameter and returns its value, and a clear function that clears the symbol table.
*/

// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SymbolTable class. The insert function 
// inserts a new variable symbol and its value into the symbol table and the lookUp function returns
// that value of the supplied variable symbol name.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "symboltable.h"
#include "multiple_initialization_exception.h"

void SymbolTable::insert(string variable, double value) {
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i].variable == variable) {
            throw MultipleInitializationException(variable);
        }
    }

    const Symbol& symbol = Symbol(variable, value);
    elements.push_back(symbol);

}

double SymbolTable::lookUp(string variable) const {
    for (int i = 0; i < elements.size(); i++)
        if (elements[i].variable == variable)
             return elements[i].value;
    return -1;
}

