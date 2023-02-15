/*
* Name: Andrew Roney
* Date: 2/14/2023
* Project: Project 2
* Description: This file contains the main function for the project 2 skeleton. It reads an input file
*  	named input.txt. It parses each statement and then evaluates it. It also contains the parseAssignments
*  	function, which parses the variable assignments in the input file.
*/

// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the main function for the project 2 skeleton. It reads an input file named input.txt
// that contains one statement that includes an expression following by a sequence of variable assignments.
// It parses each statement and then evaluates it.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"
#include "multiple_initialization_exception.h"

SymbolTable symbolTable;

void parseAssignments(stringstream& in);

int main() {
	const int SIZE = 256;
	Expression* expression;
    char paren, comma, line[SIZE];
 
	ifstream fin;//input file stream
	fin = ifstream("input.txt");//open file input.txt

	if (!(fin.is_open())) {//if file does not open
		cout << "File did not open" << endl;
		system("pause");
		return 1;
	}

	while (true) {
		symbolTable.clear();//clear the symbol table
        fin.getline(line, SIZE);
		if (!fin)
			break;
		stringstream in(line, ios_base::in); 
		in >> paren;
		cout << line << " ";
		try {//try to parse and evaluate the expression
			expression = SubExpression::parse(in);
			in >> comma;
			parseAssignments(in);
			double result = expression->evaluate();
			cout << "\nValue = " << result << endl;
		}
		catch (const MultipleInitializationException& e) {//catch multiple initialization exception
			cout << e.mie() << endl;//print the error message from the exception class in function mie()
		}
		catch (string message) {
			cout << message << endl;
		}

		cout << string(40, '=') << endl;//print 30 dashes for formatting and readability
	}
	system("pause");
	return 0;
}

void parseAssignments(stringstream& in) {
	char assignop, delimiter;
    string variable;
    double value;
	int variableCount = 0;
    do {
        variable = parseName(in);
        in >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
	
    }
    while (delimiter == ',');
}
   
