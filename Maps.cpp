//
// Created by gal on 12/19/18.
//

#include "Maps.h"

void Maps::updateVarsValuesMap(string s, double d) {
    this->varsValuesMap.find(s)->second = d;
}

void Maps::updateBindsMap(string var, string path) {
    this->bindsMap.insert(pair <string, string> (var, path));
}