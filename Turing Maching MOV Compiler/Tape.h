#pragma once
#include "AssemblySyntax.h"

using namespace std;

class Tape {
public:
	unsigned int size;
	unsigned int startIndex;
	char* letters;
	
	Tape(int size, int startIndex, char* letters);

	string toAssemblyString(AssemblySyntax& syntax);
	string getStartAddr(AssemblySyntax& syntax);
};