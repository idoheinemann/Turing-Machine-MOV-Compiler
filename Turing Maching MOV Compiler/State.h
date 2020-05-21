#pragma once
#include "Action.h"
#include "AssemblySyntax.h"
#include <iostream>
using namespace std;

class Action;

class State {
public:
	bool hasStartedGenerating = false;
	unsigned int index;
	Action* onZero;
	Action* onOne;

	State(unsigned int index);

	string toAssemblyString(AssemblySyntax& syntax);
	string stateOffset(AssemblySyntax& syntax);
};