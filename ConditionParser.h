//
// Created by noam on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_CONDITIONPARSER_H
#define INTERPRETERFLIGHT_CONDITIONPARSER_H

#include <map>
#include <vector>
#include "Command.h"

class ConditionParser : public Command {
    map<string, Expression*> commandsMap;
public:
    virtual int execute(vector<string> line) = 0;

};


#endif //INTERPRETERFLIGHT_CONDITIONPARSER_H
