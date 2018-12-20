//
// Created by noam on 12/20/18.
//

#include "BindCommand.h"

int BindCommand::execute() {
    this->maps.updateBindsMap(line[1], line[4]);
}