//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_SLEEPCOMMAND_H
#define UNTITLED5_SLEEPCOMMAND_H

#include "Command.h"

class SleepCommand: public Command {
public:
    SleepCommand(){

    }
    virtual int doCommand();
};


#endif //UNTITLED5_SLEEPCOMMAND_H
