//
// Created by noam on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_CONDITIONPARSER_H
#define INTERPRETERFLIGHT_CONDITIONPARSER_H

#include <map>
#include <vector>
#include "Command.h"
#include "Maps.h"
#include "InfixToPrefix.h"

class ConditionParser : public Command {
    Maps maps;
    //map<string, Expression*> commandsMap;
public:
    virtual int execute() = 0;

    virtual void setParams(vector<string> line) = 0;

    virtual bool checkCondition(string condition);

    bool isOperator(char s);

};


#endif //INTERPRETERFLIGHT_CONDITIONPARSER_H
