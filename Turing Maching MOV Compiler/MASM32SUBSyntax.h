#pragma once
#include "MASM32Syntax.h"

class MASM32SUBSyntax : public MASM32Syntax {
protected:
	void sub(string dst, string src, string& code) {
		code += "SUB " + dst + ", " + src + "\n";
	}
public:
	void mov(string dst, string src, string& code) {
		sub("ebp", "ebp", code); // ebp = 0
		sub("esp", "esp", code); // esp = 0
		sub("ebp", dst, code); // ebp = -dst
		sub("esp", "ebp", code); // esp = dst
		sub("ebp", "ebp", code); // ebp = 0
		sub("ebp", src, code); // ebp = -src
		sub(dst, "esp", code); // dst = 0
		sub(dst, "ebp", code); // dst = src
	}
};