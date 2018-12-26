#include "SleepCommand.h"

void SleepCommand::execute() {
    double seconds = 0;
    InfixToPrefix infToPre(this->maps);
    vector<string> splitedString;
    vector<string> result;
    splitedString = infToPre.convertToStrings(this->line[1]);
    result = infToPre.convertFunc(splitedString);
    Expression *e = infToPre.turnToExppression(result);
    seconds = (e->calculate()) * 1000;
    usleep(seconds);
}