#include "State.h"
#include <iostream>
#include <string>
using namespace std;

State::State(unsigned int index)
{
	this->hasStartedGenerating = false;
	this->index = index;
	this->onOne = NULL;
	this->onZero = NULL;
}

void State::toAssemblyString(string& code, AssemblySyntax& syntax)
{
	this->hasStartedGenerating = true;
	string zeroDir;
	string oneDir;
	if (this->onZero != NULL) {
		this->onZero->toAssemblyString(code, syntax);
		zeroDir = this->onZero->actionOffset(code, syntax);
	}
	else {
		zeroDir = "-1";
	}
	if (this->onOne != NULL) {
		this->onOne->toAssemblyString(code, syntax);
		oneDir = this->onOne->actionOffset(code, syntax);
	}
	else {
		oneDir = "-1";
	}
	string indexString = to_string(this->index);
	syntax.variable("Q_" + indexString,
		new string[2]{ zeroDir,
					   oneDir },
		2, code);
}

string State::stateOffset(string& code, AssemblySyntax& syntax)
{
	return syntax.address("Q_" + to_string(this->index), code);
}
