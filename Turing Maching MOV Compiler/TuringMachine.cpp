#include <iostream>
#include "TuringMachine.h"
using namespace std;

TuringMachine::TuringMachine(Tape* tape, State* state){
	this->tape = tape;
	this->q0 = state;
}

string TuringMachine::toAssemblyString(AssemblySyntax& syntax) {
	string code = syntax.init();
	syntax.dataSegment(code);
	this->tape->toAssemblyString(code, syntax);
	this->q0->toAssemblyString(code, syntax);


	syntax.codeSegment(code);
	syntax.mainProc(code);
	syntax.mov(syntax.getTRegister(code), this->tape->getStartAddr(code, syntax), code);
	syntax.mov(syntax.getQRegister(code), this->q0->stateOffset(code, syntax), code);

	string label = "turing_machine_operator";
	label = syntax.label(label, code);
	syntax.mov(syntax.getARegister(code), syntax.readReg(syntax.getTRegister(code), code), code); // get current letter on tape
	syntax.mov(syntax.getXRegister(code), syntax.readTwoReg(syntax.getQRegister(code), syntax.getARegister(code), code), code); // get action to perform
	syntax.mov(syntax.getDRegister(code), syntax.readReg(syntax.getXRegister(code), code), code); // get moving direction
	syntax.mov(syntax.getXRegister(code), syntax.readTwoReg(syntax.getXRegister(code), syntax.readGap(code), code), code);  // get writing char address
	syntax.mov(syntax.getYRegister(code), syntax.readReg(syntax.getXRegister(code), code), code); // get writing char
	syntax.mov(syntax.readReg(syntax.getTRegister(code), code), syntax.getYRegister(code), code); // write writing char
	syntax.mov(syntax.getTRegister(code), syntax.readTwoReg(syntax.getTRegister(code), syntax.readGap(code), code), code); // get adjacent tape cells
	syntax.mov(syntax.getTRegister(code), syntax.readTwoReg(syntax.getTRegister(code), syntax.getDRegister(code), code), code); // get next cell by direction
	syntax.mov(syntax.getQRegister(code), syntax.readTwoReg(syntax.getXRegister(code), syntax.readGap(code), code), code); // get next state

	syntax.jmp(label, code); // unconditional jump to label, this is not cheating because it is equivalent to  copying the code over and over again.
		
	syntax.endMain(code);
	return code;
}