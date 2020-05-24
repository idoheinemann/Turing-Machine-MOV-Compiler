// Turing Maching MOV Compiler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <json/json.h>
#include <fstream>

#include "TuringMachine.h"
#include "MASM32Syntax.h"
#include "NASM16Syntax.h"
#include "EMU8086Syntax.h"

using namespace std;

int main(int argc, char** argv){
    
    char* filePath = new char[512]{};
    if (argc == 1) {
        std::cout << "Enter JSON File path: " << endl;
        cin >> filePath;
    }
    else {
        filePath = argv[1];
    }
    map<const string, AssemblySyntax*> syntaxMap = {
        {"masm32", new MASM32Syntax()},
        {"nasm16", new NASM16Syntax()},
        {"emu8086", new EMU8086Syntax()}
    };
    
    Json::Value root;
    ifstream fst;
    fst.open(filePath);

    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs;
    if (!Json::parseFromStream(builder, fst, &root, &errs)) {
        std::cout << errs << std::endl;
        return EXIT_FAILURE;
    }
    AssemblySyntax* syntax = syntaxMap[root["syntax"].asString()];
    //std::cout << root << std::endl;
    Json::Value statesJson = root["states"];
    Json::Value tapeJson = root["tape"];
    State** allStates = new State * [3]{};
    for (unsigned int i = 0; i < statesJson.size(); i++) {
        allStates[i] = new State(i);
    }
    Json::Value valZero(0);
    Json::Value st;
    Json::Value act;
    string tmp = "";
    for (unsigned int i = 0; i < statesJson.size(); i++) {
        st = statesJson[i];
        if (!(act = st["0"]).isNull()) {
            int write = act["write"].asInt() ? stoi(syntax->readGap(tmp)) : 0;
            int dir = act["move"].asString() == "L" ? 0 : stoi(syntax->readGap(tmp));
            allStates[i]->onZero = new Action(i, 0, write, dir, allStates[act["next"].asInt()]);
        }
        if (!(act = st["1"]).isNull()) {
            int write = act["write"].asInt() ? stoi(syntax->readGap(tmp)) : 0;
            int dir = act["move"].asString() == "L" ? 0 : stoi(syntax->readGap(tmp));
            allStates[i]->onOne = new Action(i, 1, write, dir, allStates[act["next"].asInt()]);
        }
    }
    TuringMachine machine(new Tape(tapeJson["size"].asInt(), tapeJson["start"].asInt()), allStates[0]);
    std::cout << machine.toAssemblyString(*syntax) << endl;
    return EXIT_SUCCESS;
}
