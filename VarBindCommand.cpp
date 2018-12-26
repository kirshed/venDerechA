//
// Created by daniella on 12/18/18.
//

#include "VarBindCommand.h"

double VarBindCommand:: doCommand(){
    queue<string> tempArgs = args;
    string var = tempArgs.front();
    tempArgs.pop();
    string path = tempArgs.front();
    tempArgs.pop();
    //will add var and double to symbolTable
    if(data.addSymAndDoubleByPath(var, path)){
        //will add var and path to varPath
        data.addVPath(var, path);
    }
}