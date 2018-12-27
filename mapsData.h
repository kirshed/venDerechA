//
// Created by daniella on 12/20/18.
//

#ifndef UNTITLED5_MAPSDATA_H
#define UNTITLED5_MAPSDATA_H

#include <map>
#include <queue>
#include "string.h"

using namespace std;

class mapsData {
    map<string, double> symbolTable;
    map<string, string> varPaths;
    map<string, double> pathValues;
    bool isNewData;
    queue<string> newVars;
    unsigned long int pathNum;
public:
    mapsData(){
        makePathValues();
        isNewData = false;
        pathNum = 24;
    }

    map<string, double> getSymbolTable();
    map<string, string> getVarPaths();
    map<string, double> getPathValues();
    void addPathAndDouble(string path, double value);
    void addSymbol(string str, double dbl);
    void makePathValues();
    void addVPath(string v, string p);
    int addSymAndDoubleByPath(string v, string p);
    void updatePathByInt(int index, double value);
    string getPathByIndex(int index);
    void updateSymbolTableByPath(string path, double value);
    int updateSymDoubleByVar(string var, double value);
    void updatePathDoubleByVar(string var, double value);
    void setIsNewData(bool isNew);
    bool getIsNewData();
    void addNewVar(string str);
    queue<string>* getNewVars();
    string getPathByVar(string var);
    double getvaluebyvar(string var);
    unsigned long int getPathNum();
    void setPathNum(unsigned long int pNum);
};


#endif //UNTITLED5_MAPSDATA_H
