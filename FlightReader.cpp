//
// Created by noam on 12/13/18.
//

#include "FlightReader.h"
#include <regex>



void FlightReader::lexer(string buffer) {
    // split each line it get from the file to list of separate strings
    vector<string> info;
    size_t pos = 0;
    string delimiter = " ";
    while ((pos = buffer.find(delimiter)) != string::npos) {
        info.push_back(buffer.substr(0, pos));
        buffer.erase(0, pos + delimiter.length());
    }
    info.push_back(buffer.substr(0, pos));
    parser(info);
}

void FlightReader::parser(vector<string> info) {
    Command *c = commandsMap.find(info[0])->second;
    // erase the first element
    info.erase(info.begin());
    c->execute(info);
}

vector<string> FlightReader::openDataServerLexer(string line) {
    regex lineFormat();
    //([-+]?[0-9]\.?[0-9]+[\/\+\-\])+([-+]?[0-9]*\.?[0-9]+)
    //("(\\+|-)?[[:digit:]]+")
    //if(regex_match(input,integer))
}