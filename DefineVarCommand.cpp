//
// Created by noam on 12/18/18.
//

#include "DefineVarCommand.h"

int DefineVarCommand::execute() {
    Command *equal = new EqualCommand();
    Command *bind = new BindCommand();
    for (int i = 0; i < this->line.size(); ++i) {
        if (this->line[i] == "=") {
            if (this->line[i + 1] == "bind") {
                bind->setParams(this->line, this->maps);
                bind->execute();
            } else {
                this->line.erase(this->line.begin());
                equal->setParams(this->line, this->maps);
                equal->execute();
            }
        }
    }
}