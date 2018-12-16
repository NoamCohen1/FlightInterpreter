//
// Created by gal on 12/16/18.
//

#include "Command.h"
#include "vector"
#include "string"
using namespace std;

class openDataServerCommand : public Command {
    void doCommand(vector<string> line){
        while(line.size()!=2){
            throw "";
        }
    }
};