#pragma once
#include "MASM32Syntax.h"

class MASM32SUBSyntax : public MASM32Syntax {
protected:
	void sub(string dst, string src, string& code) {
		code += "SUB " + dst + ", " + src + "\n";
	}
	void zero(string& code) {
		sub("esp", "esp", code); // esp = 0
		sub("ebp", "ebp", code); // ebp = 0
	}
public:
	void mov(string dst, string src, string& code) {
		zero(code); // esp = ebp = 0
		sub("esp", dst, code); // esp = -dst
		sub("ebp", "esp", code); // ebp = 0 - (-dst) = dst
		sub(dst, "ebp", code); // dst = 0
		zero(code); // esp = ebp = 0
		sub("ebp", src, code); // ebp = -src
		sub(dst, "ebp", code); // dst = 0 - (-src) = src
	}
};