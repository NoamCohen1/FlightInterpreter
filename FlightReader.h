//
// Created by noam on 12/13/18.
//

#ifndef INTERPRETERFLIGHT_FLIGHTREADER_H
#define INTERPRETERFLIGHT_FLIGHTREADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <bits/stdc++.h>
#include "Command.h"
#include "ConditionParser.h"
#include "ExpressionCommand.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "SleepCommand.h"
#include "PrintCommand.h"
#include "EqualCommand.h"
#include "Maps.h"

using namespace std;

class FlightReader {
    map<string, Expression*> commandsMap;
    Maps maps;
    vector<vector<string>> ifOrWhileCommands;
    bool inWhile = false;
    int howManyBraces = 0;

public:
    FlightReader() {
        this->commandsMap.insert(pair <string, Expression*> ("openDataServer",
                                                             new ExpressionCommand(new OpenServerCommand())));
        this->commandsMap.insert(pair <string, Expression*> ("connect",
                                                             new ExpressionCommand(new ConnectCommand())));
        this->commandsMap.insert(pair <string, Expression*> ("var",
                                                             new ExpressionCommand(new DefineVarCommand())));
        this->commandsMap.insert(pair <string, Expression*> ("=",
                                                             new ExpressionCommand(new EqualCommand())));
        this->commandsMap.insert(pair <string, Expression*> ("print",
                                                             new ExpressionCommand(new PrintCommand())));
        this->commandsMap.insert(pair <string, Expression*> ("sleep",
                                                             new ExpressionCommand(new SleepCommand())));
//        this->commandsMap.insert(pair <string, Expression*> ("while",
//                                                             new ExpressionCommand(new ConditionParser())));
//        this->commandsMap.insert(pair <string, Expression*> ("if",
//                                                             new ExpressionCommand(new SleepCommand())));
    }

    bool isOperator(char s);

    vector<string> uniteParam(vector<string> info);

    void lexer(string buffer);

    void parser(vector<string> info);

//    void conditionInCondition(vector<vector<string>> commands);

};


#endif //INTERPRETERFLIGHT_FLIGHTREADER_H