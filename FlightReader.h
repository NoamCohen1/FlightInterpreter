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
#include "LoopCommand.h"
#include "IfCommand.h"
#include "ExpressionCommand.h"
#include "OpenServerCommand.h"

using namespace std;

class FlightReader {
    map<string, Expression*> commandsMap;
    vector<vector<string>> whileCommands;
    bool inWhile = false;
    int howManyBraces = 0;
public:
    FlightReader() {
        this->commandsMap.insert(pair <string, Expression*> ("openDataServer",
                new ExpressionCommand(new OpenServerCommand())));
    }

    bool isOperator(char s);

    vector<string> uniteParam(vector<string> info);

    void lexer(string buffer);

    void parser(vector<string> info);
};


#endif //INTERPRETERFLIGHT_FLIGHTREADER_H