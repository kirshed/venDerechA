//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_ASSIGNCOMMAND_H
#define UNTITLED5_ASSIGNCOMMAND_H


#include "Command.h"

class AssignCommand: public Command {
public:
    AssignCommand(){

    }

    virtual int doCommand();

};


#endif //UNTITLED5_ASSIGNCOMMAND_H
