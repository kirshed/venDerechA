//
// Created by daniella on 12/17/18.
//

#include "AssignCommand.h"

double AssignCommand::doCommand() {
    queue<string> tempArgs = args;
    string var = tempArgs.front();
    tempArgs.pop();
    string exp = tempArgs.front();
    tempArgs.pop();
    Shunting shunt = Shunting();
    double value = shunt.evaluate(exp)->calculate();
    //update symbol map according to var
    if(data.updateSymDoubleByVar(var, value)){
        //update path double map according to var path map
        data.updatePathDoubleByVar(var, value);
        data.setIsNewData(true);
        data.setNewVar(var);
    }

}
