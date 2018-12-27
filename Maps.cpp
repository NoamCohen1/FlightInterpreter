#include "Maps.h"

void Maps::updateVarsValuesMap(string s, double d) {
    this->lock();
    if (this->varsValuesMap.count(s) > 0) {
        this->varsValuesMap.find(s)->second = d;
    } else {
        this->varsValuesMap.insert(pair<string, double> (s, d));
    }
    this->unlock();
}

void Maps::updateBindsMap(string var, string path) {
    this->lock();
    if (this->bindsMap.count(var) > 0) {
        this->bindsMap.find(var)->second = path;
    } else {
        this->bindsMap.insert(pair <string, string> (var, path));
    }
    this->unlock();
}

vector<string> &Maps::replaceVarByValue(vector<string> &origin) {
    this->lock();
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
    this->unlock();
    return origin;
}

//vector<string> &Maps::replaceVarByValue(vector<string> &origin) {
//    //we will go over the vector and replace the variables by there values
//    for (int i = 0; i < origin.size(); ++i) {
//        //we will check if it is in the map
//        if(this->varsValuesMap.count(origin[i]) > 0) {
//            if (this->bindsMap.count(origin[i]) > 0) {
//                string path = this->bindsMap.find(origin[i])->second;
//                this->lock();
//                if (this->locationsAndValMap.count(path) > 0) {
//                    origin[i] = to_string(this->locationsAndValMap.find(path)->second);
//                } else {
//                    origin[i] = to_string(this->varsValuesMap.find(origin[i])->second);
//                }
//                this->unlock();
//            }
//            //swap
//            if (stod(origin[i]) < 0) {
//                origin[i] = "(0" + to_string(this->varsValuesMap.find(origin[i])->second) + ")";
//            } else {
//                origin[i] = to_string(this->varsValuesMap.find(origin[i])->second);
//            }
//        }
//    }
//    return origin;
//}

vector<string> &Maps::replaceVarByValueForPrint(vector<string> &origin) {
    this->lock();
    //we will go over the vector and replace the variables by there values
    for (int i = 0; i < origin.size(); ++i) {
        //we will check if it is in the map
        if(this->varsValuesMap.count(origin[i]) > 0) {
            //swap
            origin[i] = to_string(this->varsValuesMap.find(origin[i])->second);
        }
    }
    this->unlock();
    return origin;
}