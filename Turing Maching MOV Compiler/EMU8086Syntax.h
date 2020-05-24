#pragma once
#include "NASM16Syntax.h"

class EMU8086Syntax : public NASM16Syntax {
public:
	string address(string addr, string& code) {
		return "offset " + addr;
	}
	string constant(string name, string value, string& code) {
		code += name + " equ " + value + "\n";
		return name;
	}
};