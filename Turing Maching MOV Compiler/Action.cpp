#include "Action.h"
#include <string>

using namespace std;

Action::Action(int fromIndex, int key, int write, int direction, State* toState)
{
	this->fromIndex = fromIndex;
	this->key = key;
	this->write = write;
	this->direction = direction;
	this->toState = toState;
}

void Action::toAssemblyString(string& code, AssemblySyntax& syntax)
{
	if (!this->toState->hasStartedGenerating) {
		this->toState->toAssemblyString(code, syntax);
	}
	string keyStr = to_string(this->key);
	string fromStr = to_string(this->fromIndex);
	string tempVar = "AW" + keyStr + "_" + fromStr;
	syntax.variable(tempVar, new string[2]{ to_string(this->write), this->toState->stateOffset(code, syntax) }, 2, code);
	syntax.variable("AD" + keyStr + "_" + fromStr, new string[2]{ to_string(this->direction), syntax.address(tempVar, code) }, 2, code);
}

string Action::actionOffset(string& code, AssemblySyntax& syntax)
{
	return syntax.address("AD" + to_string(this->key) + "_" + to_string(this->fromIndex), code);
}
