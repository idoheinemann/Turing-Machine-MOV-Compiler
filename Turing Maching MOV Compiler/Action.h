#pragma once
#include "State.h"
#include "AssemblySyntax.h"

using namespace std;

class State;

class Action {
public:
	int fromIndex;
	int key;
	int write;
	int direction;
	State* toState;

	Action(int fromIndex, int key, int write, int direction, State* toState);

	void toAssemblyString(string& code, AssemblySyntax& syntax);
	string actionOffset(string& code, AssemblySyntax& syntax);
};