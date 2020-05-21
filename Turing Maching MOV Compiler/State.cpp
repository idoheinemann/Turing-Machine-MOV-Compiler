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

string State::toAssemblyString(AssemblySyntax& syntax)
{
	this->hasStartedGenerating = true;
	string res = "";
	string zeroDir;
	string oneDir;
	if (this->onZero != NULL) {
		res += this->onZero->toAssemblyString(syntax);
		zeroDir = this->onZero->actionOffset(syntax);
	}
	else {
		zeroDir = "-1";
	}
	if (this->onOne != NULL) {
		res += this->onOne->toAssemblyString(syntax);
		oneDir = this->onOne->actionOffset(syntax);
	}
	else {
		oneDir = "-1";
	}
	string indexString = to_string(this->index);
	res += syntax.dword("Q_" + indexString,
		new string[2]{ zeroDir,
					   oneDir },
		2);
	return res;
}

string State::stateOffset(AssemblySyntax& syntax)
{
	return syntax.address("Q_" + to_string(this->index));
}
