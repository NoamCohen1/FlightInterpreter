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
            if (buffer[buffer.size() -1] != ' ') {
                buffer += space;
            }
            buffer += line.at(i);
            if ((to_string(line.at(i + 1)) != space) && (i != (line.size() - 1))) {
                buffer += space;
            }
        } else if (line.at(i) == ',') {
            if (buffer[buffer.size() -1] != ' ') {
                buffer += space;
            }
            if (line.at(i + 1) == '-') {
                buffer += '0';
            }
        } else {
            buffer += line.at(i);
        }
    }
    cout << buffer << endl;

    // split each line it get from the file to list of separate strings
    vector<string> info;
    size_t pos = 0;
    string delimiter = " ";
    while ((pos = buffer.find(delimiter)) != string::npos) {
        info.push_back(buffer.substr(0, pos));
        buffer.erase(0, pos + delimiter.length());
    }
    info.push_back(buffer.substr(0, pos));
    vector<string> result;
    result = uniteParam(info);
    parser(result);
}

vector<string> FlightReader::uniteParam(vector<string> info) {
    vector<string> params;
    string param1;
    int i = 0;
    int howManyBrackets = 0;
    while (i < info.size()) {
        if(!isOperator((info[i]).at(0))) {
            if (i == (info.size() - 1)) {
                param1 += info[i];
                params.push_back(param1);
                param1 = "";
                ++i;
                continue;
            } else if (!isOperator((info[i + 1]).at(0))) {
                param1 += info[i];
                params.push_back(param1);
                param1 = "";
                ++i;
                continue;
            } else if (info[i + 1] == "(") {
                param1 += info[i];
                params.push_back(param1);
                param1 = "";
                ++i;
                continue;
            } else if ((i != 0) && (info[i - 1] == ")")) {
                params.push_back(param1);
                param1 = "";
            }
        }
        if (info[i] != "(") {
            param1 += info[i];
        }
        if (info[i] == "(") {
            howManyBrackets++;
            param1 += info[i];
            ++i;
            while (howManyBrackets != 0) {
                if (info[i] == "(") {
                    howManyBrackets++;
                }
                if (info[i] == ")") {
                    howManyBrackets--;
                }
                param1 += info[i];
                ++i;
            }
            continue;
        }
        ++i;
    }
    return params;
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