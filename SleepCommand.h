//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_SLEEPCOMMAND_H
#define UNTITLED5_SLEEPCOMMAND_H

#include "Command.h"

class SleepCommand: public Command {
    queue <string> args;
public:
    SleepCommand(queue <string> &ar) : args(ar){
        while(!ar.empty()){
            ar.pop();
        }
    }
    virtual double doCommand();
};


#endif //UNTITLED5_SLEEPCOMMAND_H
