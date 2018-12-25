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
    int sockfdServer;
    int sockfdClient;
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
        locations.emplace_back("/instrumentation/gps/indicated-vertical-speed");
        locations.emplace_back("/instrumentation/heading-indicator/indicated-heading-deg");
        locations.emplace_back("/instrumentation/magnetic-compass/indicated-heading-deg");
        locations.emplace_back("/instrumentation/slip-skid-ball/indicated-slip-skid");
        locations.emplace_back("/instrumentation/turn-indicator/indicated-turn-rate");
        locations.emplace_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
        locations.emplace_back("/controls/flight/aileron");
        locations.emplace_back("/controls/flight/elevator");
        locations.emplace_back("/controls/flight/rudder");
        locations.emplace_back("/controls/flight/flaps");
        locations.emplace_back("/controls/engines/current-engine/throttle");
        locations.emplace_back("/engines/engine/rpm");
    }


    void setLocationsAndValMap() {
        //this->locationsAndValMap.insert(pair<string, double >(,0));
    }

    void updateLocationsAndValMap(vector<double> values) {
        for (int i = 0; i < this->locations.size(); ++i) {
            if (this->locationsAndValMap.count(this->locations[i]) > 0) {
                this->locationsAndValMap.find(this->locations[i])->second = values[i];
            } else {
                this->locationsAndValMap.insert(pair<string, double >(this->locations[i], values[i]));
            }
        }
    }

    void setSockfdClient(int sockfd) {
        this->sockfdClient = sockfd;
    }

    int getSockfdClient() {
        return this->sockfdClient;
    }

    void setSockfdServer(int sockfd) {
        this->sockfdServer = sockfd;
    }

    int getSockfdServer() {
        return this->sockfdServer;
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

    double getValueFromLocation(string location) {
        return this->locationsAndValMap.find(location)->second;
    }

    void updateVarsValuesMap(string s, double d);

    void updateBindsMap(string var, string path);

    vector<string>& replaceVarByValue(vector<string> &origin);

    vector<string>& replaceVarByValueForPrint(vector<string> &origin);
};


#endif //INTERPRETERFLIGHT_MAPS_H
