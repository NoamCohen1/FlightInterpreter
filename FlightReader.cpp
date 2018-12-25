//
// Created by noam on 12/13/18.
//

#include "FlightReader.h"
#include <regex>

bool FlightReader::isOperator(char s) {
    if (s == '+' || s == '-' || s == '/' || s == '*' || s == '(' || s == ')' || s == '"' || s == '='
    || s == '>' || s == '<' || s == '!') {
        return true;
    } else {
        return false;
    }
}

void FlightReader::lexer(string line) {
    string buffer = "";
    string space = " ";
    bool sawComma = false;
    bool sawMinus = false;
    for (int i = 0; i < line.size(); ++i) {
        string s = to_string(line.at(i));
        if (line.at(i) == '{') {
            howManyBraces++;
        }
        if (line.at(i) == '}') {
            howManyBraces--;
        }
        if ((isOperator(line.at(i))) || (line.at(i) == '{') || (line.at(i) == '}')) {
            if (sawComma) {
                if ((i != 0) && (buffer[buffer.size() - 1] != ' ') && (line.at(i - 1) != ' ')) {
                    buffer += space;
                }
                if (sawMinus) {
                    buffer += ')';
                }
                if ((line.at(i) == '-') && (!sawMinus)) {
                    sawMinus = true;
                }

            }
            if ((i != 0) && (buffer[buffer.size() - 1] != ' ') && (line.at(i - 1) != ' ')) {
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
                buffer += '(' + space + '0';
                sawComma = true;
            }
        } else if (to_string(line.at(i)) == "9") {
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
        if (buffer.substr(0, pos) != "") {
            info.push_back(buffer.substr(0, pos));
        }
        buffer.erase(0, pos + delimiter.length());
    }
    if (buffer.substr(0, pos) != "") {
        info.push_back(buffer.substr(0, pos));
    }
    vector<string> result;
    if (info.size() != 0) {
        result = uniteParam(info);
        if ((result[0] == "while") && (!(this->inIf)) && (!(this->notFirstTime))) {
            this->inWhile = true;
        }
        if ((result[0] == "if") && (!(this->inWhile)) && (!(this->notFirstTime))) {
            this->inIf = true;
        }
        if (this->inWhile) {
            bool beenThereDoneThat = false;
            this->ifOrWhileCommands.push_back(result);
            if ((this->howManyBraces == 0) && (this->notFirstTime)) {
                LoopCommand loopCommand(this->ifOrWhileCommands, this->commandsMap, this->maps);
                loopCommand.execute();
                beenThereDoneThat = true;
                this->ifOrWhileCommands.clear();
                this->inWhile = false;
                this->notFirstTime = false;
            }
            if (!beenThereDoneThat) {
                this->notFirstTime = true;
            }
        } else if (this->inIf) {
            bool beenThereDoneThat = false;
            this->ifOrWhileCommands.push_back(result);
            if ((this->howManyBraces == 0) && (this->notFirstTime)) {
                IfCommand ifCommand(this->ifOrWhileCommands, this->commandsMap, this->maps);
                ifCommand.execute();
                beenThereDoneThat = true;
                this->ifOrWhileCommands.clear();
                this->inIf = false;
                this->notFirstTime = false;
            }
            if (!beenThereDoneThat) {
                this->notFirstTime = true;
            }
        } else {
            parser(result);
        }
    }
}

vector<string> FlightReader::uniteParam(vector<string> info) {
    vector<string> params;
    string param1;
    int i = 0;
    int howManyBrackets = 0;
    while (i < info.size()) {
        // if the first char in the string is not an operator
        if (!isOperator((info[i]).at(0))) {
            //
            if ((info[i] == "{") || (info[i] == "}")) {
                if (i == 0) {
                    params.push_back(info[i]);
                    ++i;
                    continue;
                }
            } else if ((i == (info.size() - 1)) && (info[i - 1] == ")")) {
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
            // if it is an operator
        } else if ((i != 0) && (info[i] == "-") && ((info[i - 1] == "=") || (isOperator(info[i - 1].at(0))))) {
            param1 += "(0" + info[i];
            i++;
            while (!(isOperator(info[i].at(0)))) {
                param1 += info[i];
                i++;
                if (i == info.size()) {
                    param1 += ")";
                    params.push_back(param1);
                    break;
                }
            }
            param1 += ")";
            continue;
        }
        if ((info[i] == "=") || (info[i] == "!") || (info[i] == "<") || (info[i] == ">")) {
            if (param1 != "") {
                params.push_back(param1);
                param1 = "";
            }
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
            //if (param1 !=)
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
        string s = this->maps->getBindsMap().find(info[0])->second;
        if (s != "") {
            Expression *c = commandsMap.find(info[1])->second;
            dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(info, this->maps);
            c->calculate();
        }
    } else {
        dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(info, this->maps);
        c->calculate();
    }
}