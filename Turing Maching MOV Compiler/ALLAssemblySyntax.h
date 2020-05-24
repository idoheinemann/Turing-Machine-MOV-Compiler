#pragma once
#include <iostream>
#include <map>
#include "AssemblySyntax.h"
#include "MASM32SUBSyntax.h"
#include "MASM32Syntax.h"
#include "NASM16Syntax.h"
#include "EMU8086Syntax.h"
#include "MASM32XORSyntax.h"

using namespace std;

extern map<const string, AssemblySyntax*> syntaxMap = {
    {"masm32", new MASM32Syntax()},
    {"nasm16", new NASM16Syntax()},
    {"emu8086", new EMU8086Syntax()},
    {"masm32sub", new MASM32SUBSyntax()},
    {"masm32xor", new MASM32XORSyntax()}
};