//
// Created by daniella on 12/19/18.
//

#ifndef UNTITLED5_MAIN_H
#define UNTITLED5_MAIN_H

#include "CommandExpression.h"

mapsData data = mapsData();

int main() {
    map<string, double> symbolTable = {};
    map<string, string> varPaths = {};
    map<string, double> pathValues = {};
    queue <string> args;
   /*args.push("10+2>5+1");
    CommandExpression* conEx = new CommandExpression(new ConditionCommand(args));
    args.push("airspeed");
    args.push("/instrumentation/airspeed-indicator/indicated-speed-kt");
    CommandExpression* bindEx = new CommandExpression(new VarBindCommand(args));
    bindEx->calculate();
    args.push("airspeed");
    args.push("15");
    CommandExpression* assEx = new CommandExpression(new AssignCommand(args));
    assEx->calculate();
    args.push("5402");
    args.push("127.0.0.1");
    ConnectCommand cli = ConnectCommand(args);
    cli.doCommand();*/
   args.push("5400");
   args.push("10");
   OpenDataServerCommand ser = OpenDataServerCommand(args);
   ser.doCommand();
    pthread_exit(NULL);
    return 0;
};


#include <string>
#include <vector>
#include "string.h"
#include "LexParse.h"
#include "fstream"
#include <iostream>

/*
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
    lexParse.lexer(lines);
    while (true){};

    return 0;
}*/

#endif //UNTITLED5_MAIN_H
