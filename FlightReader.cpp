//
// Created by noam on 12/13/18.
//

#include "FlightReader.h"
#include <regex>

bool FlightReader::isOperator(char s) {
    if (s == '+' || s == '-' || s == '/' || s == '*' || s == '(' || s == ')' || s == '"' || s == '=') {
        return true;
    } else {
        return false;
    }
}

void FlightReader::lexer(string line) {
    string buffer = "";
    string space = " ";
    for (int i = 0; i < line.size(); ++i) {
        string s = to_string(line.at(i));
        if (line.at(i) == '{') {
            howManyBraces++;
            continue;
        }
        if (line.at(i) == '}') {
            howManyBraces--;
            continue;
        }
        if (isOperator(line.at(i))) {
            if ((buffer[buffer.size() - 1] != ' ') && (line.at(i - 1) != ' ')) {
                buffer += space;
            }
            buffer += line.at(i);
            if ((i != (line.size() - 1)) && (line.at(i + 1) != ' ')) {
                buffer += space;
            }
        } else if (line.at(i) == ',') {
            if ((buffer[buffer.size() - 1] != ' ') && (line.at(i + 1) != ' ')) {
                buffer += space;
            }
            if (line.at(i + 1) == '-') {
                buffer += '0';
            }
        } else if (to_string(line.at(i)) == "9") {
            buffer += space;
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

    if ((result[0] == "while") && (!(this->inIf)) && (!(this->notFirstTime))) {
        this->inWhile = true;
        this->notFirstTime = true;
    }
    if ((result[0] == "if") && (!(this->inWhile)) && (!(this->notFirstTime))) {
        this->inIf = true;
        this->notFirstTime = true;
    }
    if (this->inWhile) {
        this->ifOrWhileCommands.push_back(result);
        if ((this->howManyBraces == 0) && (this->notFirstTime)) {
            LoopCommand loopCommand(this->ifOrWhileCommands, this->commandsMap);
            loopCommand.execute();
            this->ifOrWhileCommands.clear();
            this->inWhile = false;
            this->notFirstTime = false;
        }
    } else if (this->inIf) {
        this->ifOrWhileCommands.push_back(result);
        if ((this->howManyBraces == 0) && (this->notFirstTime)) {
            IfCommand ifCommand(this->ifOrWhileCommands, this->commandsMap);
            ifCommand.execute();
            this->ifOrWhileCommands.clear();
            this->inIf = false;
            this->notFirstTime = false;
        }
    } else {
        parser(result);
    }
}

vector<string> FlightReader::uniteParam(vector<string> info) {
    vector<string> params;
    string param1;
    int i = 0;
    int howManyBrackets = 0;
    while (i < info.size()) {
        if (!isOperator((info[i]).at(0))) {
            if ((i == (info.size() - 1)) && (info[i - 1] == ")")) {
                params.push_back(param1);
                param1 = "";
                param1 += info[i];
                params.push_back(param1);
                param1 = "";
                ++i;
                continue;
            } else if (i == (info.size() - 1)) {
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
            } else if ((info[i + 1] == "(") || (info[i + 1] == "\"")) {
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
        if (info[i] == "=") {
            params.push_back(param1);
            param1 = "";
            params.push_back(info[i]);
            ++i;
            continue;
        }
        if ((info[i] != "(") && (info[i] != "\"")) {
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
        if (info[i] == "\"") {
            //param1 += info[i];
            ++i;
            while (info[i] != "\"") {
                param1 += info[i];
                ++i;
            }
            //param1 += info[i];
            ++i;
            params.push_back(param1);
            param1 = "";
            continue;
        }
        ++i;
    }
    return params;
}

//void FlightReader::conditionInCondition(vector<vector<string>> commands) {
//    int howManyBraces = 0;
//    for (int i = 0; i < commands.size(); ++i) {
//        if (commands[i][0] == "while") {
//
//        }
//    }
//    if (result[0] == "while") {
//        this->inWhile = true;
//        howManyBraces++;
//    }
//    if (this->inWhile) {
//        this->ifOrWhileCommands.push_back(result);
//        if (howManyBraces == 0) {
//            ConditionParser *lp;
//            lp->conditionInCondition(ifOrWhileCommands);
//            ifOrWhileCommands.clear();
//            this->inWhile = false;
//        }
//    } else {
//        parser(result);
//    }
//}

void FlightReader::parser(vector<string> info) {
    Expression *c = commandsMap.find(info[0])->second;
    if (c == nullptr) {
        string s = this->maps.getBindsMap().find(info[0])->second;
        if (s != "") {
            Expression *c = commandsMap.find(info[1])->second;
            dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(info);
            c->calculate();
        }
    } else {
        dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(info);
        c->calculate();
    }
}