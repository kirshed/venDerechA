//
// Created by daniella on 12/17/18.
//

#include "IfCommand.h"

double IfCommand:: doCommand(){
    queue<Expression*> tempArgs = args;
    //first args is condition
    double con = tempArgs.front()->calculate();
    tempArgs.pop();
    if(con){
        tempArgs.front()->calculate();
        tempArgs.pop();
    }
}