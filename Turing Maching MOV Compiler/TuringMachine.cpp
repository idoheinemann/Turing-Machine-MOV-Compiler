#include <iostream>
#include "TuringMachine.h"
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
	res += syntax.mov(syntax.getTRegister(), this->tape->getStartAddr(syntax));
	res += syntax.mov(syntax.getQRegister(), this->q0->stateOffset(syntax));

	string label = "turing_machine_operator";
	res += syntax.label(label);
	res += syntax.mov(syntax.getARegister(), syntax.readReg(syntax.getTRegister())); // get current letter on tape
	res += syntax.mov(syntax.getXRegister(), syntax.readTwoReg(syntax.getQRegister(), syntax.getARegister())); // get action to perform
	res += syntax.mov(syntax.getDRegister(), syntax.readReg(syntax.getXRegister())); // get moving direction
	res += syntax.mov(syntax.getXRegister(), syntax.readTwoReg(syntax.getXRegister(), syntax.readGap()));  // get writing char address
	res += syntax.mov(syntax.getYRegister(), syntax.readReg(syntax.getXRegister())); // get writing char
	res += syntax.mov(syntax.readReg(syntax.getTRegister()), syntax.getYRegister()); // write writing char
	res += syntax.mov(syntax.getTRegister(), syntax.readTwoReg(syntax.getTRegister(), syntax.readGap())); // get adjacent tape cells
	res += syntax.mov(syntax.getTRegister(), syntax.readTwoReg(syntax.getTRegister(), syntax.getDRegister())); // get next cell by direction
	res += syntax.mov(syntax.getQRegister(), syntax.readTwoReg(syntax.getXRegister(), syntax.readGap())); // get next state

	res += syntax.jmp(label); // unconditional jump to label, this is not cheating because it is equivalent to  copying the code over and over again.
		
	res += syntax.endMain();
	return res;
}