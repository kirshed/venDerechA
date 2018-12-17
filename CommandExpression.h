//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_COMMANDEXPRESSION_H
#define UNTITLED5_COMMANDEXPRESSION_H


#include "Expression.h"
#include "Command.h"
#include "ConnectCommand.h"
#include "OpenDataServerCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "AssignCommand.h"
#include "IfCommand.h"
#include "VarCommand.h"
#include "BindCommand.h"

class CommandExpression: public Expression {
    Command* myCom;
public:
    CommandExpression(Command* command){
        myCom = command;
    }

    virtual double calculate() const;
};


#endif //UNTITLED5_COMMANDEXPRESSION_H
