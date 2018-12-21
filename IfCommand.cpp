//
// Created by noam on 12/18/18.
//

#include "IfCommand.h"

int IfCommand::execute() {
    vector<vector<string>> vectors;
    if (checkCondition(this->commands[0][1])) {
        for (int i = 0; i < this->commands.size(); ++i) {
            if ((i != 0) && (this->commands[i][0] == "if")) {
                vectors = conditionInCondition(this->commands, i);
                IfCommand ifCommand(vectors, this->commandsMap);
                ifCommand.execute();
            } else if (this->commands[i][0] == "while") {
                vectors = conditionInCondition(this->commands, i);
                LoopCommand loopCommand(vectors, this->commandsMap);
                loopCommand.execute();
            } else {
                Expression *c = commandsMap.find(this->commands[i][0])->second;
                if (c == nullptr) {
                    string s = this->maps.getBindsMap().find(this->commands[i][0])->second;
                    if (s != "") {
                        Expression *c = commandsMap.find(this->commands[i][1])->second;
                        dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(this->commands[i]);
                        c->calculate();
                    }
                } else {
                    dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(this->commands[i]);
                    c->calculate();
                }
            }
        }
    }
}