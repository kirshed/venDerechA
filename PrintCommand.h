//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_PRINTCOMMAND_H
#define UNTITLED5_PRINTCOMMAND_H

#include "Command.h"
class PrintCommand: public Command {
public:
    queue <string> args;
    PrintCommand(queue <string> &ar) : args(ar){
        while(!ar.empty()){
            ar.pop();
        }
    }
    virtual double doCommand();
};


#endif //UNTITLED5_PRINTCOMMAND_H
