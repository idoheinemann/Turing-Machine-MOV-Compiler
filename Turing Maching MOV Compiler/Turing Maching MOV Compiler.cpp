// Turing Maching MOV Compiler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "TuringMachine.h"
#include "MASMSyntax.h"
using namespace std;

int main(){
    Tape t;
    t.size = 100;
    t.startIndex = 10;
    t.letters = new char[100];
    AssemblySyntax* syntax = new MASMSyntax();
    cout << t.toAssemblyString(*syntax);

    char buffer[80];
    cin >> buffer;
}
