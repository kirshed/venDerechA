//
// Created by daniella on 12/16/18.
//

#include "LexParse.h"

using namespace std;

void LexParse:: lexer(ifstream& data){
    string str;
    string temp;
    //vector<string> tempLex;
    while (getline(data, str)) {
        for(string::iterator it = str.begin(); it != str.end(); ++it){
            long long int index = 0;
            index = str.find(" ", 0);
            temp = str.substr(0, index);
            //adding command name to tempLax vector
            lexed.push_back(temp);
            str.substr(index+1, str.size());
            //adding command arguments to tempLax vector
            lexed.push_back(str);
        }
    }

}

void LexParse:: parser(){
    int i = 0;
    string str;
    while(i<lexed.size()){
      str = lexed[i];
        if(str == "openDataServer"){
            ceMap.insert(pair<string, Expression*> (lexed[i],
                    new CommandExpression(new OpenDataServerCommand())));

            
        }
        else if(str == "Connect"){
            ceMap.insert(pair<string, Expression*> (lexed[i],
                                                    new CommandExpression(new ConnectCommand())));

        }
        else if(str == "var"){
            ceMap.insert(pair<string, Expression*> (lexed[i],
                                                    new CommandExpression(new VarCommand())));
            //צריך גם לעדכן מפה של הvar

        }
        else if(str == "while"){
            ceMap.insert(pair<string, Expression*> (lexed[i],
                                                    new CommandExpression(new WhileCommand())));

        }
        else if(str == "if"){
            ceMap.insert(pair<string, Expression*> (lexed[i],
                                                    new CommandExpression(new IfCommand())));

        }
        else if(str == "sleep"){
            ceMap.insert(pair<string, Expression*> (lexed[i],
                                                    new CommandExpression(new SleepCommand())));

        }
        else{
            //צריך לבדוק אם זה varנמצא במפה ולפעול בהתאם
            // אחרת נזרוק אקספשן

        }
        //will probably change to i+ whatever int doCommand() returns
        i++;
    }
}



