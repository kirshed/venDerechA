//
// Created by daniella on 12/16/18.
//

#include "Shunting.h"
// CPP program to evaluate a given
// expression where tokens are
// separated by space.
#include <bits/stdc++.h>
using namespace std;

//NEED TO DEAL WITH NEGATIVES AND DECIMALS

// Function to find precedence of
// operators.
int Shunting:: getPrec(char op) const{
    //if the operator is valid
    if(precedence.count(op)){
        return this->precedence.at(op);
    }
    else{
        //throw "invalid operator";
        return 0;
    }
}

// Function to perform arithmetic operations.
Expression* Shunting:: applyOp(Expression* a, Expression* b, char op){
    switch(op){
        case '+': return new Plus(a, b);
        case '-': return new Minus(a, b);
        case '*': return new Mul(a, b);
        case '/': return new Div(a, b);
    }
}

// Function that returns value of
// expression after evaluation.
Expression* Shunting:: evaluate(string exp){
    string tokens = fixString(exp);
    int i;
    // stack to store integer values.
    stack <Expression*> values;

    // stack to store operators.
    stack <char> ops;

    for(i = 0; i < tokens.length(); i++){

        // Current token is a whitespace,
        // skip it.
        if(tokens[i] == ' ')
            continue;

            // Current token is an opening
            // brace, push it to 'ops'
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }

            // Current token is a number, push
            // it to stack for numbers.
        else if(isdigit(tokens[i])){
            double val = 0;

            // There may be more than one
            // digits in number.
            while(i < tokens.length() &&
                  isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
            if((i < tokens.length() &&tokens[i] == '.')){
                i++;
                double div = 10;
                double dec = (tokens[i]-'0')/div;
                div*=10;
                i++;
                while(i < tokens.length() &&
                      isdigit(tokens[i]))
                {
                    dec = dec + (tokens[i]-'0')/div;
                    div*=10;
                    i++;
                }
                val = val+dec;
            }
            i--;
            Expression* valEx = new Number(val);
            values.push(valEx);
        }

            // Closing brace encountered, solve
            // entire brace.
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                Expression* val2 = values.top();
                values.pop();

                Expression* val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }

            // pop opening brace.
            ops.pop();
        }

        //letter - CHECK THIS
        else if(tokens[i]!='+'&&tokens[i]!='-'&&tokens[i]!='*'&&tokens[i]!='/'){
            string valString;
            //will find string from map - removed isdigit check.
            while(tokens[i]!='+'&&tokens[i]!='-'&&tokens[i]!='*'&&tokens[i]!='/'&&i<tokens.size()&&tokens[i]!=')'){
                valString+=tokens[i];
                i++;
            }
            //once i get to the end of the symbol name we need to decrease i because we increase i in the loop
            i--;
            //should prob change this to double
            double myVal = int(data.getSymbolTable().at(valString));
            Expression* exVal = new Number(myVal);
            values.push(exVal);
        }
            // Current token is an operator.
        else
        {

            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while(!ops.empty() && getPrec(ops.top()) >= getPrec(tokens[i])){
                if(values.size()<2){

                }
                Expression* val2 = values.top();
                values.pop();

                Expression* val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while(!ops.empty()){
        Expression* val2 = values.top();
        values.pop();

        Expression* val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    stack <Expression*> retValues = values;
    // Top of 'values' contains result, return it.
    return retValues.top();
}

string Shunting:: fixString(string tokens){
    string digit;
    string final = "";
    for(int i = 0; i<tokens.size(); i++){
        string num = "";
        if(tokens[i] == '-'&&(tokens[i-1] == '*'||tokens[i-1] == '/')){
            //string until before -
            string beg = tokens.substr(0, i);
            i++;
            while(isdigit(tokens[i])||tokens[i] == '.'){
                string digit(1,tokens[i]);
                num+=digit;
                i++;
            }
            string end = tokens.substr(i, tokens.size());
            tokens = beg+"(0-"+num+")"+end;
        }
    }
    //if the string starts with 0
    if(tokens[0] == '-'){
        tokens = "0"+tokens;
    }
    return tokens;
}

/*int main() {
    Shunting sh = Shunting();
    Expression* e = sh.evaluate("12.2*4");
    cout<< e->calculate();
    return 0;
}*/