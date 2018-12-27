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
    for(unsigned long int i = 0; i<con.size();i++){
        if(con.at(i) == '<'){
            con1 = con.substr(0, i);
            //<=
            if(con.at(i+1) == '='){
                 con2 = con.substr(i+2, con.size());
                double check = (shunt.evaluate(con1)->calculate())<= (shunt.evaluate(con2)->calculate());
                return check;
            }
            con2 = con.substr(i+1, con.size());
            double check = (shunt.evaluate(con1)->calculate())< (shunt.evaluate(con2)->calculate());
            return check;
        }
        else if(con.at(i) == '>'){
            con1 = con.substr(0, i);
            //<=
            if(con.at(i+1) == '='){
                con2 = con.substr(i+2, con.size());
                double check = (shunt.evaluate(con1)->calculate())>= (shunt.evaluate(con2)->calculate());
                return check;
            }
            con2 = con.substr(i+1, con.size());
            double check = (shunt.evaluate(con1)->calculate())> (shunt.evaluate(con2)->calculate());
            return check;
        }
        //=
        else if(con.at(i) == '='){
            con1 = con.substr(0, i);
            con2 = con.substr(i+1, con.size());
            double check = (shunt.evaluate(con1)->calculate()) == (shunt.evaluate(con2)->calculate());
            return check;
        }
    }

    //the condition is made of one expression for example while(true)
    double ans = shunt.evaluate(con)->calculate();
    return ans;
}