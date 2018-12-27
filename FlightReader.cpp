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
    // if it the command Enterc
    if (line == "Enterc") {
        vector<string> temp;
        temp.push_back(line);
        Expression *c = commandsMap.find(line)->second;
        dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(temp, this->maps);
        c->calculate();
        return;
    }
    string buffer = "";
    string space = " ";
    bool sawComma = false;
    bool sawMinus = false;
    // pass on the string and organize it with spaces between each argument
    for (int i = 0; i < line.size(); ++i) {
        string s = to_string(line.at(i));
        if (line.at(i) == '{') {
            howManyBraces++;
        }
        if (line.at(i) == '}') {
            howManyBraces--;
        }
        // if it is an operator
        if ((isOperator(line.at(i))) || (line.at(i) == '{') || (line.at(i) == '}')) {
            // if we saw a ','
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
            //if we are after the space
            if ((i != 0) && (buffer[buffer.size() - 1] != ' ') && (line.at(i - 1) != ' ')) {
                buffer += space;
            }
            buffer += line.at(i);
            if ((i != (line.size() - 1)) && (line.at(i + 1) != ' ')) {
                buffer += space;
            }
            // if we have the , and - after we add (0-value)
        } else if (line.at(i) == ',') {
            if ((buffer[buffer.size() - 1] != ' ') && (line.at(i + 1) != ' ')) {
                buffer += space;
            }
            if (line.at(i + 1) == '-') {
                buffer += '(' + space + '0';
                sawComma = true;
            }
            // if there is tab
        } else if (to_string(line.at(i)) == "9") {
            buffer += space;
        } else {
            buffer += line.at(i);
        }
    }

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
        // if we have while or if we read all the lines after and make a vector of vectors of lines
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
                // if we are at the end we push it
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
        // split
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
        // if there is (()) we count how many brackets
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

void FlightReader::parser(vector<string> info) {
    if (commandsMap.count(info[0]) <= 0) {
        //string s = this->maps->getBindsMap().find(info[0])->second;
        if (this->maps->getBindsMap().count(info[0]) > 0) {
            Expression *c = commandsMap.find(info[1])->second;
            dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(info, this->maps);
            c->calculate();
        }
    } else {
        // we make a new command by the first word
        Expression *c = commandsMap.find(info[0])->second;
        dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(info, this->maps);
        c->calculate();
    }
}

void FlightReader::exit() {
    //close the sockets
    close(maps->getSockfdClient());
    close(maps->getSockfdServer());
    maps->setStateOfSockets(false);
    //go over the maps and clear them
    map<string, Expression *>::iterator iterator;
    for (iterator = commandsMap.begin(); iterator != commandsMap.end(); ++iterator) {
        delete (iterator->second);
    }
    commandsMap.clear();
}