//
// Created by daniella on 12/16/18.
//

#include <list>
#include "LexParse.h"
#include "OpenDataServerCommand.h"
#include "ConnectCommand.h"
#include "SleepCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "VarCommand.h"
#include "VarBindCommand.h"
#include "AssignCommand.h"
#include "ConditionCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"

using namespace std;

/**
 * this function get lines from file, reorganize them, and make them Command Expression
 * @param vector<string> lines
 */
void LexParse::lexer(vector<string> lines) {
    vector<CommandExpression *> commands;

    //send to fun that initialize the map of sign
    initializeSign();

    //run on the file lines, and reorganize the string correctly to expressions
    for (int i = 0; i < lines.size(); i++) {
        vector<string> vec = createString(lines.at(i));
        vector<string> exVec = fromStringToExp(vec);

        //insert to our main map
        this->commandsMap.insert(pair<int, vector<string>>(i, exVec));
    }

    //send the map to parser that make it Command Expression
    commands = parser(this->commandsMap);

    //for every Command Expression send to calculate func
    for (CommandExpression *c: commands) {
        c->calculate();
    }
}

/**
 * this function initialize the sign map we have in the class
 */
void LexParse::initializeSign() {
    this->sign.insert(pair<char, int>(')', 1));
    this->sign.insert(pair<char, int>('(', 1));
    this->sign.insert(pair<char, int>(',', 1));
    this->sign.insert(pair<char, int>('=', 1));
    this->sign.insert(pair<char, int>('.', 1));
    this->sign.insert(pair<char, int>('<', 1));
    this->sign.insert(pair<char, int>('>', 1));
    this->sign.insert(pair<char, int>('!', 1));
    this->sign.insert(pair<char, int>('+', 1));
    this->sign.insert(pair<char, int>('-', 1));
    this->sign.insert(pair<char, int>('*', 1));
    this->sign.insert(pair<char, int>('/', 1));
}

/**
 * this function take the string from the file and reorganize it correctly,
 * and return a vector that hold the string
 * @param string l
 * @return vector<string>
 */
vector<string> LexParse::createString(string l) {
    unsigned long index = 0;
    vector<string> temp;

    //run until the string get to the end
    while (index != l.length()) {

        //if index = " "
        if (l.at(index) == ' ') {
            index++;
            continue;
        }

        //if digit
        if (isdigit(l.at(index))) {
            string val = "";

            //the number can hold more than one digit
            while ((index <= l.length() - 1) && (isdigit(l[index]) || (l.at(index) == '.'))) {
                val += l[index];
                index++;
            }

            index--;

            temp.push_back(val);


        }
            //if one of the operations
        else if (this->sign.count(l.at(index)) || (l.at(index) == '{')
                 || (l.at(index) == '}')) {
            char c = l.at(index);
            string s = "";
            s += c;
            temp.push_back(s);
        }
            //if a char
        else if (((l.at(index) >= 'A') && (l.at(index) <= 'Z')) || ((l.at(index) >= 'a') && (l.at(index) <= 'z'))) {
            string val = "";

            //the word can hold more than one char
            while (index < l.length() && (l.at(index) != ' ') && (l.at(index) != 9) && (l.at(index) != ',')
                   && (l.at(index) != '\n') && (l.at(index) != '<') && (l.at(index) != '>') && (l.at(index) != '+')
                   && (l.at(index) != '-') && (l.at(index) != '/') && (l.at(index) != '*') && (l.at(index) != '=')
                   && (l.at(index) != ')') && (l.at(index) != '(')) {
                if (index != l.length() - 1 && (l.at(index) == '!')
                    && (l.at(index + 1) == '=')) { break; }
                val += (l[index]);
                index++;
            }
            index--;
            temp.push_back(val);
        }
            //expression in ""
        else if (l.at(index) == '"') {
            string val = "";
            val += '"';
            index++;
            while (index < l.length() && (l.at(index) != '"')) {
                val += (l[index]);
                index++;
            }
            val += "\"";
            temp.push_back(val);
        }
        index++;
    }
    return temp;
}

/**
 * this function take the vector of string and split it to args that going to be expression (after the parser)
 * @param vector<string> str
 * @return vector<string>
 */
vector<string> LexParse::fromStringToExp(vector<string> str) {
    vector<string> expressions;

    vector<string>::iterator it;
    for (it = str.begin(); it != str.end(); ++it) {
        //in case we have "while" or "if"
        if((str.at(0) == "while") || (str.at(0) == "if")) {
            expressions.push_back(str.at(0));
            int i = 1;
            string condition = "";
            while (str.at(i) != "{"){
                if ((str.at(i) == "(") || (str.at(i) == ")")){
                    i++;
                    continue;
                }
                condition += str.at(i);
                i++;
            }
            expressions.push_back(condition);
            it == str.end();
            break;
        }

        //if a word
        if (((*it).at(0) == '"') || (((*it).at(0) >= 'a') && ((*it).at(0) <= 'z'))
            || (((*it).at(0) >= 'A') && ((*it).at(0) <= 'Z'))) {
            expressions.push_back((*it));
        } else if ((*it) == "=") {
            expressions.push_back((*it));
        } else if ((*it) == "{") { continue; }
        else if ((*it) == "}") {
            expressions.push_back(*it);
            continue;
        } else {
            //split to separated expressions
            string var = "";
            //if this is a number and the next one is also a number
            while ((*it) != ",") {
                if (isdigit((*it).at(0))) {
                    if (it + 1 == str.end()) {
                        var += *it;
                        break;
                    } else if (it != str.end() && (!this->sign.count((*(it + 1)).at(0)))) {
                        var += *it;
                        break;
                    }
                } else if (((*(it - 1)) == ")") && (!this->sign.count((*it).at(0)))) {
                    it--;
                    break;
                }
                var += *it;
                if (it != str.end()) {
                    it++;
                }
            }
            if (var != "") {
                expressions.push_back(var);
            }
        }
    }

    //in case of connect check numbers of dots
    if(expressions.at(0) == "connect") {
        vector<string> connectExpression;
        string newS = "";
        int i = 1;
        while (i != expressions.size()-1) {
            newS += expressions.at(i);
            i++;
        }
        connectExpression.push_back(str.at(0));
        connectExpression.push_back(newS);
        connectExpression.push_back(expressions.at(i));

        int dot = 0;
        for(char& c : connectExpression.at(1)) {
            if (c == '.') {
                dot++;
            }
        }
        if (dot !=3){
            throw "illigal number!";
        } else {
            return connectExpression;
        }
    }

    return expressions;
}

/**
 * this function for every vector of args in the map, create the correct Command Expression
 * @param map<int, vector<string>> commandsMap
 * @return vector<CommandExpression *>
 */
vector<CommandExpression *> LexParse::parser(map<int, vector<string>> commandsMap){
    vector<CommandExpression *> commandVector;

    //for every string in the map, create the correct Command Expression
    for (map<int, vector<string>>::iterator it = commandsMap.begin(); it != commandsMap.end(); it++) {
        if ((*it).second.at(0) == "openDataServer") {
            if ((*it).second.size() != 3) { throw "illegal operation!"; }
            queue<string> args;
            args.push((*it).second.at(1));
            args.push((*it).second.at(2));
            commandVector.push_back(new CommandExpression(new OpenDataServerCommand(args)));
        } else if ((*it).second.at(0) == "connect") {
            if ((*it).second.size() != 3) { throw "illegal operation!"; }
            queue<string> args;
            args.push((*it).second.at(1));
            args.push((*it).second.at(2));
            commandVector.push_back(new CommandExpression(new ConnectCommand(args)));
        } else if ((*it).second.at(0) == "var") {
            if ((*it).second.size() < 4) { throw "illegal operation!"; }
            if ((*it).second.at(3) == "bind") {
                queue<string> args;
                args.push((*it).second.at(1));
                args.push((*it).second.at(4));
                commandVector.push_back(new CommandExpression(new VarBindCommand(args)));
            } else {
                queue<string> args;
                args.push((*it).second.at(1));
                args.push((*it).second.at(3));
                commandVector.push_back(new CommandExpression(new VarCommand(args)));
            }
        } else if (((*it).second.at(0) == "while") || ((*it).second.at(0) == "if")) {
            string conditionType = (*it).second.at(0);
            int counter = 1;
            int i = 0;
            queue<string> args;
            queue<Expression *> conditionQueue;
            map<int, vector<string>> newMap;

            args.push((*it).second.at(1));
            conditionQueue.push(new CommandExpression(new ConditionCommand(args)));

            it++;
            bool hadWhileOrIf = false;
            //go over all the string in the loop, enter to new map and send again to parser (recursive)
            while (counter != 0) {
                if ((*it).second.at(0) == "}") {
                    if (hadWhileOrIf && (counter != 1)) {
                        newMap.insert(pair<int, vector<string>>(i, (*it).second));
                    }
                    if (counter != 1) {
                        it++;
                        i++;
                    }
                    counter--;
                    continue;
                } else if (((*it).second.at(0) == "while") || ((*it).second.at(0) == "if")) {
                    hadWhileOrIf = true;
                    counter++;
                }
                newMap.insert(pair<int, vector<string>>(i, (*it).second));
                it++;
                i++;
            }

            LexParse recursive = LexParse();
            vector<CommandExpression *> r = recursive.parser(newMap);

            for (vector<CommandExpression *>::iterator itory = r.begin(); itory != r.end(); itory++) {
                conditionQueue.push(*itory);
            }

            if (conditionType == "while") {
                commandVector.push_back(new CommandExpression(new WhileCommand(conditionQueue)));
            } else if (conditionType == "if") {
                commandVector.push_back(new CommandExpression(new IfCommand(conditionQueue)));
            }
        } else if ((*it).second.at(0) == "sleep") {
            queue<string> args;
            args.push((*it).second.at(1));
            commandVector.push_back(new CommandExpression(new SleepCommand(args)));
        } else if ((*it).second.at(0) == "print") {
            queue<string> args;
            args.push((*it).second.at(1));
            commandVector.push_back(new CommandExpression(new PrintCommand(args)));
        } else { // expression in pattern: "breaks = 0" / "rudder = (h0-heading)/20"
            queue<string> args;
            args.push((*it).second.at(0));
            args.push((*it).second.at(2));
            commandVector.push_back(new CommandExpression(new AssignCommand(args)));
        }
    }
    return commandVector;
}
