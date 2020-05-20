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

string Action::toAssemblyString(AssemblySyntax& syntax)
{
	string res = "";
	if (!this->toState->hasStartedGenerating) {
		res += this->toState->toAssemblyString(syntax);
	}
	string keyStr = to_string(this->key);
	string fromStr = to_string(this->fromIndex);
	string tempVar = "AW" + keyStr + "_" + fromStr;
	res += syntax.dword(tempVar, new string[2]{ to_string(this->write), this->toState->stateOffset(syntax) }, 2);
	res += syntax.dword("AD" + keyStr + "_" + fromStr, new string[2]{ to_string(this->direction), syntax.address(tempVar) }, 2);
	return res;
}

string Action::actionOffset(AssemblySyntax& syntax)
{
	return string();
}
