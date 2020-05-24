#pragma once
#pragma once
#include "MASM32Syntax.h"

class MASM32XORSyntax : public MASM32Syntax {
protected:
	// this does not follow my convention because "xor" in lowercase isn't allowed
	void XOR(string dst, string src, string& code) {
		code += "XOR " + dst + ", " + src + "\n";
	}
public:
	void mov(string dst, string src, string& code) {
		XOR("ebp", "ebp", code); // ebp = 0
		XOR("esp", "esp", code); // esp = 0
		XOR("esp", src, code); // esp = src
		XOR("ebp", dst, code); // ebp = dst
		XOR(dst, "ebp", code); // dst = 0
		XOR(dst, "esp", code); // dst = src
	}
};