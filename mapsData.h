//
// Created by daniella on 12/20/18.
//

#ifndef UNTITLED5_MAPSDATA_H
#define UNTITLED5_MAPSDATA_H

#include <map>
#include "string.h"

using namespace std;

class mapsData {
    map<string, double> symbolTable;
    map<string, string> varPaths;
    map<string, double> pathValues;
    bool isNewData;
    string newVar;
public:
    mapsData(){
        makePathValues();
        isNewData = false;
    }

    map<string, double> getSymbolTable();
    map<string, string> getVarPaths();
    map<string, double> getPathValues();
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
    void setNewVar(string str);
    string getNewVar();
    string getPathByVar(string var);
    double getvaluebyvar(string var);
};


#endif //UNTITLED5_MAPSDATA_H
