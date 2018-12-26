//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_COMMAND_H
#define UNTITLED5_COMMAND_H
#include <iostream>
#include <queue>
#include "Expression.h"
#include "Shunting.h"
#include <pthread.h>

using namespace std;

class Command{
public:
    virtual double doCommand() = 0;
};

#endif //UNTITLED5_COMMAND_H
