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
	res += syntax.mov(A, syntax.readReg(T)); // get current letter on tape
	res += syntax.mov(X, syntax.readTwoReg(Q, A)); // get action to perform
	res += syntax.mov(D, syntax.readReg(X)); // get moving direction
	res += syntax.mov(X, syntax.readTwoReg(X, syntax.readGap()));  // get writing char address
	res += syntax.mov(Y, syntax.readReg(X)); // get writing char
	res += syntax.mov(syntax.readReg(T), Y); // write writing char
	res += syntax.mov(T, syntax.readTwoReg(T, syntax.readGap())); // get adjacent tape cells
	res += syntax.mov(T, syntax.readTwoReg(T, D)); // get next cell by direction
	res += syntax.mov(Q, syntax.readTwoReg(X, syntax.readGap())); // get next state

	res += syntax.jmp(label); // unconditional jump to label, this is not cheating because it is equivalent to  copying the code over and over again.
		
	res += syntax.endMain();
	return res;
}