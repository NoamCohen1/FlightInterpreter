//
// Created by gal on 12/19/18.
//

#include "Maps.h"

void Maps::updateVarsValuesMap(string s, double d) {
    this->varsValuesMap.insert(pair<string, double> (s, d));
}

void Maps::updateBindsMap(string var, string path) {
    this->bindsMap.insert(pair <string, string> (var, path));
}

vector<string> &Maps::replaceVarByValue(vector<string> &origin) {
    //we will go over the vector and replace the variables by there values
    for (int i = 0; i < origin.size(); ++i) {
        //we will check if it is in the map
        if(this->varsValuesMap.count(origin[i]) > 0) {
            //swap
            if (this->varsValuesMap.find(origin[i])->second < 0) {
                origin[i] = "(0" + to_string(this->varsValuesMap.find(origin[i])->second) + ")";
            } else {
                origin[i] = to_string(this->varsValuesMap.find(origin[i])->second);
            }
        }
    }
    return origin;
}