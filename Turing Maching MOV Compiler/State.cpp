#include "State.h"
#include <iostream>
#include <string>
using namespace std;

State::State(int index)
{
	this->index = index;
}

string State::toAssemblyString(AssemblySyntax& syntax)
{
	this->hasStartedGenerating = true;
	string res = this->onZero->toAssemblyString(syntax);
	res += this->onOne->toAssemblyString(syntax);
	string indexString = to_string(this->index);
	res += syntax.dword("Q_" + indexString,
		new string[2]{ this->onZero->actionOffset(syntax),
					   this->onOne->actionOffset(syntax) },
		2);
	return res;
}

string State::stateOffset(AssemblySyntax& syntax)
{
	return syntax.address("Q_" + to_string(this->index));
}
