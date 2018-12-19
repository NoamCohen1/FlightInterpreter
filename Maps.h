//
// Created by gal on 12/19/18.
//

#ifndef INTERPRETERFLIGHT_MAPS_H
#define INTERPRETERFLIGHT_MAPS_H

#include <map>
#include <string>
#include <string.h>

using namespace std;

class Maps {
    //map<string, Expression*> commandsMap;
    int sockfd;
    map<string, string> bindsMap;
    map<string, double> varsValuesMap;
public:
    Maps() {
//        this->commandsMap.insert(pair <string, Expression*> ("openDataServer",
//                                                             new ExpressionCommand(new OpenServerCommand())));
//        this->commandsMap.insert(pair <string, Expression*> ("connect",
//                                                             new ExpressionCommand(new ConnectCommand())));
//        this->commandsMap.insert(pair <string, Expression*> ("var",
//                                                             new ExpressionCommand(new DefineVarCommand())));

//        this->bindsMap.insert(pair <string, string> ("breaks", "/controls/flight/speedbrake"));
//        this->bindsMap.insert(pair <string, string> ("throttle", "/controls/engines/engine/throttle"));
//        this->bindsMap.insert(pair <string, string> ("airspeed",  "/instrumentation/airspeed-indicator/indicated-speed-kt"));
//        this->bindsMap.insert(pair <string, string> ("roll", "/instrumentation/attitude-indicator/indicated-roll-deg"));
//        this->bindsMap.insert(pair <string, string> ("pitch", "/instrumentation/attitude-indicator/internal-pitch-deg"));
//        this->bindsMap.insert(pair <string, string> ("rudder", "/controls/flight/rudder"));
//        this->bindsMap.insert(pair <string, string> ("aileron", "/controls/flight/aileron"));
//        this->bindsMap.insert(pair <string, string> ("elevator", "/controls/flight/elevator"));
//        this->bindsMap.insert(pair <string, string> ("alt", "/instrumentation/altimeter/indicated-altitude-ft"));
//        this->bindsMap.insert(pair <string, string> ("h0", "/controls/flight/elevator"));
    }

    void setSockfd(int sockfd) {
        this->sockfd = sockfd;
    }

    int getSockfd() {
        return this->sockfd;
    }

//    map<string, Expression*> getCommandsMap() {
//        return commandsMap;
//    }
    map<string, string> getBindsMap() {
        return bindsMap;
    }
    map<string, double> getVarsValuesMap() {
        return varsValuesMap;
    }
};


#endif //INTERPRETERFLIGHT_MAPS_H
