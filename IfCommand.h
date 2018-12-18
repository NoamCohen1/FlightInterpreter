//
// Created by noam on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_IFCOMMAND_H
#define INTERPRETERFLIGHT_IFCOMMAND_H

#include "ConditionParser.h"

class IfCommand : public ConditionParser {
    vector<vector<string>> commands;
public:
    IfCommand(vector<vector<string>> commands) {
        this->commands = commands;
    }

    virtual int execute();

    virtual void setParams(vector<string> line) {}
};


#endif //INTERPRETERFLIGHT_IFCOMMAND_H
