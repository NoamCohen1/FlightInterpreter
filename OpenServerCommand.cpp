//
// Created by gal on 12/17/18.
//

#include "OpenServerCommand.h"

struct MyParams {
    int port;
    int sock;
};

void* thread_func(void* arg) {
    struct MyParams* params = (struct MyParams*) arg;
//    for (int i = 0; i < params->x; ++i)	{
//        cout << params->y;
//    }
//    cout << endl;
//    params.port = 0;
//    params.sock = '@';
//    return params;
}

int OpenServerCommand::execute() {
    if (line.size() != 3) {
        throw "The Number of Arguments is Not Correct";
    }
    InfixToPrefix infToPre;
    vector<string> strings;
    vector<string> stringsConverted;
    vector<Expression*> expressions;
    for (int i = 1; i < line.size(); ++i) {
        strings = infToPre.convertToStrings(line[i]);
        stringsConverted = infToPre.convertFunc(strings);
        Expression *e = infToPre.turnToExppression(stringsConverted);
        expressions.push_back(e);
    }

    int socketPort = (int) expressions[1]->calculate();
    int Hz = (int) expressions[2]->calculate();

    struct MyParams *params = new MyParams();
    params->port = socketPort;
    params->sock = socket(AF_INET, SOCK_STREAM, 0);
    pthread_t trid;
    pthread_create(&trid, nullptr, thread_func, params);
    //pthread_join(&trid, &params);
    return 0;
}

