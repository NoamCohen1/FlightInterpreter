//
// Created by gal on 12/19/18.
//

#include "EqualCommand.h"

int EqualCommand::execute() {
    string s = this->line[2];
    double d = 0;
    if ((this->maps.getVarsValuesMap().count(s)) > 0) {
        d = this->maps.getVarsValuesMap().find(s)->second;
        this->maps.updateVarsValuesMap(this->line[0], d);
    } else {
        InfixToPrefix infToPre;
        vector<string> strings;
        vector<string> stringsConverted;
        strings = infToPre.convertToStrings(s);
        stringsConverted = infToPre.convertFunc(strings);
        Expression *e = infToPre.turnToExppression(stringsConverted);
        d = e->calculate();
        this->maps.updateVarsValuesMap(this->line[0], d);
    }
    string newValue;
    if ((this->maps.getBindsMap().count(this->line[0])) > 0) {
        newValue = "set " + this->maps.getBindsMap().find(this->line[0])->second + " " + to_string(d);
        this->setValue(newValue);
    }
}

void EqualCommand::setValue(string newValue) {
    int sockfd = this->maps.getSockfd();
    char *c = const_cast<char*>(newValue.c_str());
    /* Send message to the server */
    int n = write(sockfd, c, strlen(c));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}