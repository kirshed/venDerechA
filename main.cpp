//
// Created by daniella on 12/19/18.
//

#ifndef UNTITLED5_MAIN_H
#define UNTITLED5_MAIN_H

#include "CommandExpression.h"

bool shouldStop = false;

mapsData data = mapsData();

/*int main() {
    map<string, double> symbolTable = {};
    map<string, string> varPaths = {};
    map<string, double> pathValues = {};
    queue<string> args;
    args.push("breaks");
    args.push("/controls/flight/speedbrake");
    VarBindCommand vbind = VarBindCommand(args);
    vbind.doCommand();
    args.push("breaks");
    args.push("20");
    AssignCommand ascom = AssignCommand(args);
    ascom.doCommand();
    args.push("5402");
    args.push("127.0.0.1");
    ConnectCommand cli = ConnectCommand(args);
    cli.doCommand();
    pthread_exit(NULL);
    return 0;
};*/


#include <string>
#include <vector>
#include "string.h"
#include "LexParse.h"
#include "fstream"
#include <iostream>


int main(int argc, char *argv[]) {

    if (argc != 2) {
        throw "illegal input!";
    }

    LexParse lexParse = LexParse();
    string sentence;
    vector<string> lines;

    ifstream myFile;
    myFile.open(argv[1]);

    //read line by line from the file and insert it to vector of string
    if (myFile.is_open()) {
        while (getline(myFile, sentence)) {
            lines.push_back(sentence);
        }
    }

    myFile.close();

    //send the string vector to LexParse
    try {
        lexParse.lexer(lines);
    }   catch (const char* s)   {
        cout << s << endl;
    }

   // while (true){};

    return 0;
}

#endif //UNTITLED5_MAIN_H
