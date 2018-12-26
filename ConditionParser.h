#ifndef INTERPRETERFLIGHT_CONDITIONPARSER_H
#define INTERPRETERFLIGHT_CONDITIONPARSER_H

#include <map>
#include <vector>
#include "Command.h"
#include "Maps.h"
#include "InfixToPrefix.h"
#include "ExpressionCommand.h"

class ConditionParser : public Command {
protected:
    Maps *maps;
    //map<string, Expression*> commandsMap;
public:
    virtual void execute() = 0;

    virtual void setParams(vector<string> line, Maps *maps) {
        this->maps = maps;
    }

    virtual bool findCondition(vector<string> condition);

    bool isOperator(string s);

    vector<vector<string>> conditionInCondition(vector<vector<string>> vectors, int &i);

    bool checkTheCondition(vector<string> condition);
};


#endif //INTERPRETERFLIGHT_CONDITIONPARSER_H
