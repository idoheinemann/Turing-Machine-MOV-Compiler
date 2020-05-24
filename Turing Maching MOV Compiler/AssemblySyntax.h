#pragma once
#include <iostream>
using namespace std;

class AssemblySyntax {

public:
	virtual string init() = 0;
	virtual void dataSegment(string& code) = 0;
	virtual void codeSegment(string& code) = 0;
	virtual void mov(string dst, string src, string& code) = 0;
	virtual void mainProc(string& code) =0;
	virtual void endMain(string& code) = 0;
	virtual void jmp(string label, string& code) = 0;
	virtual string variable(string name, string* values, int valuesCount, string& code) = 0;
	virtual string label(string name, string& code) = 0;
	virtual string constant(string name, string value, string& code) = 0;
	virtual string address(string addr, string& code) = 0;
	virtual string readReg(string reg, string& code) = 0;
	virtual string readTwoReg(string reg1, string reg2, string& code) = 0;
	virtual string readGap(string& code) = 0;
	virtual string getTRegister(string& code) = 0;
	virtual string getQRegister(string& code) = 0;
	virtual string getDRegister(string& code) = 0;
	virtual string getARegister(string& code) = 0;
	virtual string getXRegister(string& code) = 0;
	virtual string getYRegister(string& code) = 0;
};