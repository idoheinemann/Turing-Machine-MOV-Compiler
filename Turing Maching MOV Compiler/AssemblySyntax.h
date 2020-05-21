#pragma once
#include <iostream>
using namespace std;

class AssemblySyntax {

public:
	virtual string init() = 0;
	virtual string dataSegment() = 0;
	virtual string codeSegment() = 0;
	virtual string mov(string dst, string src) = 0;
	virtual string address(string addr) = 0;
	virtual string dword(string name, string* values, int valuesCount) = 0;
	virtual string mainProc() =0;
	virtual string endMain() = 0;
	virtual string label(string name) = 0;
	virtual string jmp(string label) = 0;
	virtual string constant(string name, string value) = 0;
	virtual string readReg(string reg) = 0;
	virtual string readTwoReg(string reg1, string reg2) = 0;
	virtual string readGap() = 0;
};