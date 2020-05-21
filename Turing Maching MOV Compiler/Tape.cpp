#include "Tape.h"

#include <iostream>
#include <string>


using namespace std;

string Tape::getStartAddr(AssemblySyntax& syntax) {
	return syntax.address("T_" + to_string(this->startIndex));
}

Tape::Tape(unsigned int size, unsigned int startIndex)
{
	this->size = size;
	this->startIndex = startIndex;
}

string Tape::toAssemblyString(AssemblySyntax& syntax) {
	string ret = "";
	string tempVar = "";
	string leftName = "";
	string rightName = "";
	for (unsigned int i = 0; i < this->size; i++) {
		if (i == 0) {
			leftName = "0";
		}
		else {
			leftName = syntax.address("T_" + to_string(i - 1));
		}
		if (i == this->size - 1) {
			rightName = "0";
		}
		else {
			rightName = syntax.address("T_" + to_string(i + 1));
		}
		tempVar = "NT_" + to_string(i);
		ret += syntax.dword(tempVar, new string[2]{ leftName, rightName }, 2);
		ret += syntax.dword("T_" + to_string(i), new string[2]{ "0", syntax.address(tempVar) }, 2);
	}
	return ret;
}