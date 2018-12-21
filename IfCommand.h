//
// Created by noam on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_IFCOMMAND_H
#define INTERPRETERFLIGHT_IFCOMMAND_H

#pragma once
#include "ConditionParser.h"
#include "LoopCommand.h"

class IfCommand : public ConditionParser {
    vector<vector<string>> commands;
    map<string, Expression*> commandsMap;
public:
    IfCommand(vector<vector<string>> commands, map<string, Expression*> commandsMap) {
        this->commands = commands;
        this->commandsMap = commandsMap;
    }

    virtual int execute();

    virtual void setParams(vector<string> line) {}
};


#endif //INTERPRETERFLIGHT_IFCOMMAND_H
