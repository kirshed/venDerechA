//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_ASSIGNCOMMAND_H
#define UNTITLED5_ASSIGNCOMMAND_H


#include "Command.h"

extern mapsData data;

class AssignCommand: public Command {
public:
    queue <string> args;
    AssignCommand(queue <string> &ar) : args(ar){
        while(!ar.empty()){
            ar.pop();
        }
    }

    virtual double doCommand();
};


#endif //UNTITLED5_ASSIGNCOMMAND_H
