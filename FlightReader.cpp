//
// Created by noam on 12/13/18.
//

#include "FlightReader.h"
#include <regex>

bool FlightReader::isOperator(char s){
    if (s == '+' || s == '-' || s == '/' || s == '*' || s == '(' || s == ')' || s == '"'){
        return true;
    }
    else{
        return false;
    }
}

void FlightReader::lexer(string line) {
    string buffer = "";
    string space = " ";
    for (int i = 0; i < line.size(); ++i) {
        //char s = line.at(i);
        if (isOperator(line.at(i))) {
            buffer += space + line.at(i);
            if ((to_string(line.at(i + 1)) != space) && (i != (line.size() - 1))) {
                buffer += space;
            }
        } else if (line.at(i) == ',') {
            buffer += space;
        } else {
            buffer += line.at(i);
        }
    }
    //cout << buffer << endl;

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

vector<string> FlightReader::uniteParam(vector<string> info) {
    vector<string> params;
    string param1;
    for (int i = 0; i < info.size(); ++i) {
        if ((info[i]) == "(") {
            while((info[i]) != ")") {
                params.push_back(param1);
            }
        }

    }
}

void FlightReader::parser(vector<string> info) {
    //Command *c = commandsMap.find(info[0])->second;
    // erase the first element
    info.erase(info.begin());
    //c->execute(info);
}

vector<string> FlightReader::openDataServerLexer(string line) {
    regex lineFormat();
    //([-+]?[0-9]\.?[0-9]+[\/\+\-\])+([-+]?[0-9]*\.?[0-9]+)
    //("(\\+|-)?[[:digit:]]+")
    //if(regex_match(input,integer))
}