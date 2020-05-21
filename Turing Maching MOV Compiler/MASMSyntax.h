#pragma once
#include "AssemblySyntax.h"

class MASMSyntax : public AssemblySyntax {
	string init() {
		return  "include \\masm32\\include\\masm32rt.inc\n";
	}
	string dataSegment() {
		return ".data\n";
	}
	string codeSegment() {
		return ".code\n";
	}
	string mov(string dst, string src) {
		return "MOV " + dst + ", " + src + "\n";
	}
	string address(string addr) {
		return "OFFSET " + addr;
	}
	string dword(string name, string* values, int valuesCount) {
		string ret = name + " DWORD ";
		for (int i = 0; i < valuesCount; i++) {
			ret += values[i];
			if (i != valuesCount - 1) {
				ret += ", ";
			}
		}
		return ret + "\n";
	}
	string mainProc() {
		return "main proc\n";
	}
	string endMain() {
		return "main endp\nend main\n";
	}
	string label(string name) {
		return name + ":\n";
	}
	string jmp(string label) {
		return "jmp " + label + "\n";
	}
	string constant(string name, string value) {
		return name + " equ " + value + "\n";
	}
	string readReg(string addr) {
		return "[" + addr + "]";
	}
	string readTwoReg(string reg1, string reg2) {
		return "[" + reg1 + " + " + reg2 + "]";
	}
	string readGap() {
		return "4";
	}
};