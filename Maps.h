//
// Created by gal on 12/19/18.
//

#ifndef INTERPRETERFLIGHT_MAPS_H
#define INTERPRETERFLIGHT_MAPS_H

#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Maps {
    //map<string, Expression*> commandsMap;
    int sockfd;
    map<string, string> bindsMap;
    map<string, double> varsValuesMap;
    map<string, double> locationsAndValMap;
    vector<string> locations;
    //vector<double> values;
public:
    Maps() {
        locations.emplace_back("/instrumentation/airspeed-indicator/indicated-speed-kt");
        locations.emplace_back("/instrumentation/altimeter/indicated-altitude-ft");
        locations.emplace_back("/instrumentation/altimeter/pressure-alt-ft");
        locations.emplace_back("/instrumentation/attitude-indicator/indicated-pitch-deg");
        locations.emplace_back("/instrumentation/attitude-indicator/indicated-roll-deg");
        locations.emplace_back("/instrumentation/attitude-indicator/internal-pitch-deg");
        locations.emplace_back("/instrumentation/attitude-indicator/internal-roll-deg");
        locations.emplace_back("/instrumentation/encoder/indicated-altitude-ft");
        locations.emplace_back("/instrumentation/encoder/pressure-alt-ft");
        locations.emplace_back("/instrumentation/gps/indicated-altitude-ft");
        locations.emplace_back("/instrumentation/gps/indicated-ground-speed-kt");
        locations.emplace_back("/instrumentation/gps/indicated-vertical-speed</node>");
        locations.emplace_back("/instrumentation/heading-indicator/indicated-heading-deg");
        locations.emplace_back("/instrumentation/magnetic-compass/indicated-heading-deg");
        locations.emplace_back("/instrumentation/slip-skid-ball/indicated-slip-skid");
        locations.emplace_back("/instrumentation/turn-indicator/indicated-turn-rate");
        locations.emplace_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
        locations.emplace_back("/controls/flight/aileron");
        locations.emplace_back("/controls/flight/rudder");
        locations.emplace_back("/controls/flight/flaps");
        locations.emplace_back("/controls/engines/engine/throttle");
        locations.emplace_back("/engines/engine/rpm");


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

    void setLocationsAndValMap() {
        //this->locationsAndValMap.insert(pair<string, double >(,0));
    }

    void updateLocationsAndValMap(vector<double> values) {
        for (int i = 0; i < this->locationsAndValMap.size(); ++i) {
            this->locationsAndValMap.insert(pair<string, double >(this->locations[i], values[i]));
        }
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

    map<string, double> getLocationsAndValMap() {
        return locationsAndValMap;
    }

    void updateVarsValuesMap(string s, double d);

    void updateBindsMap(string var, string path);

    vector<string>& replaceVarByValue(vector<string> &origin);
};


#endif //INTERPRETERFLIGHT_MAPS_H
