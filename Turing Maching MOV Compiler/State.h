#pragma once
#include "Action.h"
#include "AssemblySyntax.h"
#include <iostream>
using namespace std;

class Action;

class State {
public:
	bool hasStartedGenerating = false;
	int index;
	Action* onZero;
	Action* onOne;

	State(int index);

	string toAssemblyString(AssemblySyntax& syntax);
	string stateOffset(AssemblySyntax& syntax);
};