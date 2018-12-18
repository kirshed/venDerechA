//
// Created by daniella on 12/17/18.
//

#include "VarCommand.h"

//one option: var a = 50*100 or any expression
double VarCommand:: doCommand(){
    Shunting myShunt = Shunting();
    double value = myShunt.evaluate(args.front())->calculate();
    args.pop();
    return value;
}