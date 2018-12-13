//
// Created by noam on 12/13/18.
//

#include "FlightReader.h"

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
    for (int i = 0; i < info.size(); ++i) {
        map<string, Expression>::iterator iterator;
        // find the command matches the string
        for (iterator = this->commandsMap.begin(); iterator != this->commandsMap.end(); ++iterator) {
            if (info[i] == (iterator->first)) {

            }
        }
    }
}