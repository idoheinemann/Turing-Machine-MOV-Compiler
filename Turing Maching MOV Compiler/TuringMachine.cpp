#include <iostream>
#include "TuringMachine.h"
#include "Registers.h"
using namespace std;

TuringMachine::TuringMachine(Tape* tape, State* state){
	this->tape = tape;
	this->q0 = state;
}

string TuringMachine::toAssemblyString(AssemblySyntax& syntax) {
	string res = syntax.init();
	res += syntax.dataSegment();
	res += this->tape->toAssemblyString(syntax);
	res += this->q0->toAssemblyString(syntax);


	res += syntax.codeSegment();
	res += syntax.mainProc();
	res += syntax.mov(T, this->tape->getStartAddr(syntax));
	res += syntax.mov(Q, this->q0->stateOffset(syntax));

	string label = "turing_machine_operator";
	res += syntax.label(label);



	res += syntax.jmp(label);

	return res;
}