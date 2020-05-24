#include "Tape.h"

#include <iostream>
#include <string>


using namespace std;

string Tape::getStartAddr(string& code, AssemblySyntax& syntax) {
	return syntax.address("T_" + to_string(this->startIndex), code);
}

Tape::Tape(unsigned int size, unsigned int startIndex)
{
	this->size = size;
	this->startIndex = startIndex;
}

void Tape::toAssemblyString(string& code, AssemblySyntax& syntax) {
	string tempVar = "";
	string leftName = "";
	string rightName = "";
	for (unsigned int i = 0; i < this->size; i++) {
		if (i == 0) {
			leftName = "-1";
		}
		else {
			leftName = syntax.address("T_" + to_string(i - 1), code);
		}
		if (i == this->size - 1) {
			rightName = "-1";
		}
		else {
			rightName = syntax.address("T_" + to_string(i + 1), code);
		}
		tempVar = "NT_" + to_string(i);
		syntax.variable(tempVar, new string[2]{ leftName, rightName }, 2, code);
		syntax.variable("T_" + to_string(i), new string[2]{ "0", syntax.address(tempVar, code) }, 2, code);
	}
}