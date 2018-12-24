//
// Created by noam on 12/18/18.
//

#include "LoopCommand.h"

int LoopCommand::execute() {
    vector<vector<string>> vectors;
    while (findCondition(this->commands[0])) {
        for (int i = 0; i < this->commands.size(); ++i) {
            if ((i != 0) && (this->commands[i][0] == "while")) {
                vectors = conditionInCondition(this->commands, i);
                LoopCommand loopCommand(vectors, this->commandsMap);
                loopCommand.execute();
            } else if (this->commands[i][0] == "if") {
                vectors = conditionInCondition(this->commands, i);
                IfCommand ifCommand(vectors, this->commandsMap);
                ifCommand.execute();
            } else {
                if (commandsMap.count(this->commands[i][0]) <= 0) {
                    if (this->maps.getBindsMap().count(this->commands[i][0]) > 0) {
                        string s = this->maps.getBindsMap().find(this->commands[i][0])->second;
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