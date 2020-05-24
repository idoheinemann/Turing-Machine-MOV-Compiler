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
		XOR("ebp", "ebp", code);
		XOR("ebp", dst, code); // ebp = dst
		XOR(dst, "ebp", code); // dst = 0
		XOR("ebp", "ebp", code);
		XOR("ebp", src, code); // ebp = src
		XOR(dst, "ebp", code);
	}
};