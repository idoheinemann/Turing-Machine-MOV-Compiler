#pragma once
#include "AssemblySyntax.h"

class NASM16Syntax : public AssemblySyntax {
public:
	string init() {
		string code = "";
		jmp("_start", code);
		return code;
	}
	void dataSegment(string& code) {
	}
	void codeSegment(string& code) {
	}
	void mov(string dst, string src, string& code) {
		code += "MOV " + dst + ", " + src + "\n";
	}
	string address(string addr, string& code) {
		return addr;
	}
	string variable(string name, string* values, int valuesCount, string& code) {
		string ret = name + " DW ";
		for (int i = 0; i < valuesCount; i++) {
			ret += values[i];
			if (i != valuesCount - 1) {
				ret += ", ";
			}
		}
		code += ret + "\n";
		return name;
	}
	void mainProc(string& code) {
		code += "_start:\n";
	}
	void endMain(string& code) {
	}
	void jmp(string label, string& code) {
		code += "JMP " + label + "\n";
	}
	string label(string name, string& code) {
		code += name + ":\n";
		return name;
	}
	string constant(string name, string value, string& code) {
		code += "%define " + name + " " + value + "\n";
		return name;
	}
	string readReg(string addr, string& code) {
		mov("bx", addr, code);
		return "[bx]";
	}
	string readTwoReg(string reg1, string reg2, string& code) {
		mov("bx", reg1, code);
		mov("si", reg2, code);
		return "[bx + si]";
	}
	string readGap(string& code) {
		return "2";
	}
	string getTRegister(string& code) {
		return "ax";
	}
	string getQRegister(string& code) {
		return "cx";
	}
	string getDRegister(string& code) {
		return "dx";
	}
	string getARegister(string& code) {
		return "di";
	}
	string getXRegister(string& code) {
		return "bp";
	}
	string getYRegister(string& code) {
		return "sp";
	}
};