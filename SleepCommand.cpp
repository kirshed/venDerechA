//
// Created by daniella on 12/17/18.
//

#include "SleepCommand.h"
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std;

double SleepCommand::doCommand() {
    Shunting shunt = Shunting();
    double sleepTime = shunt.evaluate(args.front())->calculate();
    this_thread::sleep_for(chrono::milliseconds(int(sleepTime)));
    args.pop();
}