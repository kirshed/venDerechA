//
// Created by daniella on 12/16/18.
//

#include "Shunting.h"
// CPP program to evaluate a given
// expression where tokens are
// separated by space.
#include <bits/stdc++.h>
using namespace std;

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
Expression* Shunting:: evaluate(string tokens){
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
            //CHECK IF NECESSARY
            //i++;
        }

            // Current token is a number, push
            // it to stack for numbers.
        else if(isdigit(tokens[i])){
            int val = 0;

            // There may be more than one
            // digits in number.
            while(i < tokens.length() &&
                  isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
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
            //CHECK IF NECESSARY
            //i++;
        }

            // Current token is an operator.
        else
        {
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while(!ops.empty() && getPrec(ops.top()) >= getPrec(tokens[i])){
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

    // Top of 'values' contains result, return it.
    return values.top();
}

string Shunting::getStr() {return this->myStr;}

int main() {
    Shunting sh = Shunting("100 * ( 2 + 12 ) / 14");
    Expression* e = sh.evaluate(sh.getStr());
    cout<< e->calculate();
    return 0;
}