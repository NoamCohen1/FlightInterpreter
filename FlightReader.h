//
// Created by noam on 12/13/18.
//

#ifndef INTERPRETERFLIGHT_FLIGHTREADER_H
#define INTERPRETERFLIGHT_FLIGHTREADER_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Command.h"

using namespace std;

class FlightReader {
    map<string, Expression> commandsMap;
public:

    void lexer(string buffer);

    void parser(vector<string> info);
};


#endif //INTERPRETERFLIGHT_FLIGHTREADER_H
