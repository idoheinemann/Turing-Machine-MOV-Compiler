#pragma once
#include "AssemblySyntax.h"

class MASM32Syntax : public AssemblySyntax {
public:
	string init() {
		return "include \\masm32\\include\\masm32rt.inc\n";
	}
	void dataSegment(string& code) {
		code += ".data\n";
	}
	void codeSegment(string& code) {
		code += ".code\n";
	}
	void mov(string dst, string src, string& code) {
		code += "MOV " + dst + ", " + src + "\n";
	}
	string address(string addr, string& code) {
		return "OFFSET " + addr;
	}
	string variable(string name, string* values, int valuesCount, string& code) {
		string ret = name + " DWORD ";
		for (int i = 0; i < valuesCount; i++) {
			ret += values[i];
			if (i != valuesCount - 1) {
				ret += ", ";
			}
		}
		code +=  ret + "\n";
		return name;
	}
	void mainProc(string& code) {
		code += "main proc\n";
	}
	void endMain(string& code) {
		code += "main endp\nend main\n";
	}
	void jmp(string label, string& code) {
		code += "JMP " + label + "\n";
	}
	string label(string name, string& code) {
		code += name + ":\n";
		return name;
	}
	string constant(string name, string value, string& code) {
		code += name + " equ " + value + "\n";
		return name;
	}
	string readReg(string addr, string& code) {
		return "[" + addr + "]";
	}
	string readTwoReg(string reg1, string reg2, string& code) {
		return "[" + reg1 + " + " + reg2 + "]";
	}
	string readGap(string& code) {
		return "4";
	}
	string getTRegister(string& code) {
		return "eax";
	}
	string getQRegister(string& code) {
		return "ebx";
	}
	string getDRegister(string& code) {
		return "ecx";
	}
	string getARegister(string& code) {
		return "edx";
	}
	string getXRegister(string& code) {
		return "esi";
	}
	string getYRegister(string& code) {
		return "edi";
	}
};