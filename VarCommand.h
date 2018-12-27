//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_VARCOMMAND_H
#define UNTITLED5_VARCOMMAND_H


#include "Command.h"
#include "mapsData.h"

extern mapsData data;

class VarCommand: public Command {
    queue<string> args;
public:
    VarCommand(queue<string> &ar) : args(ar) {
        while(!ar.empty()){
            ar.pop();
        }
    }

    virtual double doCommand();
};


#endif //UNTITLED5_VARCOMMAND_H
