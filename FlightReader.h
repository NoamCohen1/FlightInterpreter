//
// Created by noam on 12/13/18.
//

#ifndef INTERPRETERFLIGHT_FLIGHTREADER_H
#define INTERPRETERFLIGHT_FLIGHTREADER_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bits/stdc++.h>
#include "Command.h"

using namespace std;

class FlightReader {
    //map<string, Expression*> commandsMap;
public:
    bool isOperator(char s);

    vector<string> uniteParam(vector<string> info);

    void lexer(string buffer);

    void parser(vector<string> info);

    vector<string> openDataServerLexer(string line);
};


#endif //INTERPRETERFLIGHT_FLIGHTREADER_H
