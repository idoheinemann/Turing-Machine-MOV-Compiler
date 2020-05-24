#pragma once
#include "AssemblySyntax.h"

using namespace std;

class Tape {
public:
	unsigned int size;
	unsigned int startIndex;
	
	Tape(unsigned int size, unsigned int startIndex);

	void toAssemblyString(string& code, AssemblySyntax& syntax);
	string getStartAddr(string& code, AssemblySyntax& syntax);
};