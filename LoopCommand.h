#ifndef INTERPRETERFLIGHT_LOOPCOMMAND_H
#define INTERPRETERFLIGHT_LOOPCOMMAND_H

#pragma once
#include <map>
#include "ConditionParser.h"
#include "IfCommand.h"

class LoopCommand : public ConditionParser {
    vector<vector<string>> commands;
    map<string, Expression*> commandsMap;
public:
    LoopCommand(vector<vector<string>> commands, map<string, Expression*> commandsMap, Maps *maps) {
        this->commands = commands;
        this->commandsMap = commandsMap;
        this->maps = maps;
    }

    virtual void execute();

    virtual void setParams(vector<string> line, Maps *maps) {}
};

#endif //INTERPRETERFLIGHT_LOOPCOMMAND_H
