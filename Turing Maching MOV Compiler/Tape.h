#pragma once
#include "AssemblySyntax.h"

using namespace std;

class Tape {
public:
	unsigned int size;
	unsigned int startIndex;
	
	Tape(unsigned int size, unsigned int startIndex);

	string toAssemblyString(AssemblySyntax& syntax);
	string getStartAddr(AssemblySyntax& syntax);
};