//
// Created by daniella on 12/18/18.
//

#ifndef UNTITLED5_VARBINDCOMMAND_H
#define UNTITLED5_VARBINDCOMMAND_H


#include "Command.h"

extern mapsData data;

class VarBindCommand: public Command {
    queue<string> args;
public:
    VarBindCommand(queue<string> &ar) : args(ar){
        while(!ar.empty()){
            ar.pop();
        }
    }

    virtual double doCommand();
};


#endif //UNTITLED5_VARBINDCOMMAND_H
