//
// Created by daniella on 12/19/18.
//

#include <algorithm>
#include "ConditionCommand.h"
#include "CommandExpression.h"

double ConditionCommand:: doCommand(){
    queue<string> tempArgs = args;
    Shunting shunt = Shunting();
    string con = tempArgs.front();
    tempArgs.pop();
    string con1;
    string con2;
    //looking for operator in string
    for(int i = 0; i<con.size();i++){
        if(con.at(i) == '<'){
            con1 = con.substr(0, i);
            //<=
            if(con.at(i+1) == '='){
                 con2 = con.substr(i+2, con.size());
                return (shunt.evaluate(con1)->calculate())<= (shunt.evaluate(con2)->calculate());
            }
            con2 = con.substr(i+1, con.size());
            return (shunt.evaluate(con1)->calculate())< (shunt.evaluate(con2)->calculate());
        }
        else if(con.at(i) == '>'){
            con1 = con.substr(0, i);
            //<=
            if(con.at(i+1) == '='){
                con2 = con.substr(i+2, con.size());
                return (shunt.evaluate(con1)->calculate())>= (shunt.evaluate(con2)->calculate());
            }
            con2 = con.substr(i+1, con.size());
            return (shunt.evaluate(con1)->calculate())> (shunt.evaluate(con2)->calculate());
        }
        //=
        else if(con.at(i) == '='){
            con1 = con.substr(0, i);
            con2 = con.substr(i+1, con.size());
            return (shunt.evaluate(con1)->calculate()) == (shunt.evaluate(con2)->calculate());
        }
    }

    //the condition is made of one expression for example while(true)
    double ans = shunt.evaluate(con)->calculate();
    return ans;
}