//
// Created by daniella on 12/17/18.
//

#include "SleepCommand.h"
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std;

double SleepCommand::doCommand() {
    queue<string> tempArgs = args;
    Shunting shunt = Shunting();
    double sleepTime = shunt.evaluate(tempArgs.front())->calculate();
    this_thread::sleep_for(chrono::milliseconds(int(sleepTime)));
    tempArgs.pop();
}