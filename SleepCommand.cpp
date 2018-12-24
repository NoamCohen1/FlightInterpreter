//
// Created by noam on 12/20/18.
//

#include "SleepCommand.h"

int SleepCommand::execute() {
    double seconds = 0;
    InfixToPrefix infToPre(this->maps);
    vector<string> splitedString;
    vector<string> result;
    splitedString = infToPre.convertToStrings(this->line[1]);
    result = infToPre.convertFunc(splitedString);
    Expression *e = infToPre.turnToExppression(result);
    seconds = (e->calculate()) * 1000;
    sleep(seconds);
}