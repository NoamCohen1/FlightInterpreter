#include "IfCommand.h"

void IfCommand::execute() {
    vector<vector<string>> vectors;
    int i;
    if (findCondition(this->commands[0])) {
        for (i = 0; i < this->commands.size(); ++i) {
            if ((i != 0) && (this->commands[i][0] == "if")) {
                vectors = conditionInCondition(this->commands, i);
                IfCommand ifCommand(vectors, this->commandsMap, this->maps);
                ifCommand.execute();
            } else if (this->commands[i][0] == "while") {
                vectors = conditionInCondition(this->commands, i);
                LoopCommand loopCommand(vectors, this->commandsMap, this->maps);
                loopCommand.execute();
            } else {
                if (commandsMap.count(this->commands[i][0]) <= 0) {
                    if (this->maps->getBindsMap().count(this->commands[i][0]) > 0) {
                        Expression *c = commandsMap.find(this->commands[i][1])->second;
                        dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(this->commands[i], this->maps);
                        c->calculate();
                    } else if (this->maps->getVarsValuesMap().count(this->commands[i][0]) > 0) {
                        Expression *c = commandsMap.find(this->commands[i][1])->second;
                        dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(this->commands[i], this->maps);
                        c->calculate();
                    }
                } else {
                    Expression *c = commandsMap.find(this->commands[i][0])->second;
                    dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(this->commands[i], this->maps);
                    c->calculate();
                }
            }
        }
    }
}