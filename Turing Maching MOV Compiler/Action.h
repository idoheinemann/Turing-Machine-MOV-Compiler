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

	string toAssemblyString(AssemblySyntax& syntax);
	string actionOffset(AssemblySyntax& syntax);
};