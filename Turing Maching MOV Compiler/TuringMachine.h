#pragma once
#include "Tape.h"
#include "State.h"

using namespace std;

class TuringMachine {
public:
	TuringMachine(Tape*, State*);
	Tape* tape;
	State* q0;

	string toAssemblyString(AssemblySyntax& syntax);
};