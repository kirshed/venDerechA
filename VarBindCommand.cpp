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
    unsigned long int gersh = path.find('"');
    path = path.substr(gersh+1, path.size());
    gersh = path.find('"');
    path = path.substr(0, path.size()-1);
    //will add var and double to symbolTable
    if(data.addSymAndDoubleByPath(var, path)){
        //will add var and path to varPath
        data.addVPath(var, path);
    }
    //path does not exist in xml table
    else{
        //adding var and 0 to symbolTable
        data.addSymbol(var, 0);

        //adding var and path to varPaths map
        data.addVPath(var, path);

        //getting index for path
        unsigned long int pindex = data.getPathNum();
        //adding relevant index to begining of new path
        string myPath = to_string(pindex)+path;
        //adding path with index and 0 to varPaths map
        data.addPathAndDouble(myPath, 0);

        //updating pathNum
        ++pindex;
        data.setPathNum(pindex);


    }
}