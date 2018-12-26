#include "ConditionParser.h"

bool ConditionParser::isOperator(string s){
    if (s == ">" || s == "<" || s == "=" || s == "!"){
        return true;
    }
    else{
        return false;
    }
}

vector<vector<string>> ConditionParser::conditionInCondition(vector<vector<string>> vectors, int &i) {
    int howManyBraces = 0;
    vector<vector<string>> result;
    for (i; i < vectors.size(); ++i) {
        result.push_back(vectors[i]);
        for (int k = 0; k < vectors[i].size(); ++k) {
            if (vectors[i][k] == "{") {
                howManyBraces++;
                break;
            }
        }
        if (howManyBraces != 0) {
            break;
        }
    }
    while (howManyBraces != 0) {
        i++;
        result.push_back(vectors[i]);
        for (int k = 0; k < vectors[i].size(); ++k) {
            if (vectors[i][k] == "{") {
                howManyBraces++;
            }
            if (vectors[i][k] == "}") {
                howManyBraces--;
            }
        }
    }
    return result;
}

bool ConditionParser::findCondition(vector<string> condition) {
    vector<string> onlyCondition;
    vector<string> twoParts;
    bool sawOperator = false;
    string left = "";
    string right = "";
    string theOperator = "";
    for (int j = 0; j < condition.size(); ++j) {
        if ((condition[j] != "while") && (condition[j] != "if") && (condition[j] != "{")) {
            onlyCondition.push_back(condition[j]);
        }
    }
    for (int i = 0; i < onlyCondition.size(); ++i) {
        if (isOperator(onlyCondition[i])) {
            theOperator += onlyCondition[i];
            sawOperator = true;
        } else if (!(isOperator(onlyCondition[i])) && !sawOperator) {
            left += onlyCondition[i];
        } else if (!(isOperator(onlyCondition[i])) && sawOperator) {
            right += onlyCondition[i];
        }
    }
    twoParts.push_back(left);
    twoParts.push_back(theOperator);
    twoParts.push_back(right);
    return this->checkTheCondition(twoParts);
}

bool ConditionParser::checkTheCondition(vector<string> condition) {
    //we want to turn them to expressions and calculate each one of them
    double left = 0;
    double right = 0;
    InfixToPrefix infToPre(this->maps);
    vector<string> stringsLeft;
    vector<string> resultLeft;
    vector<string> stringsRight;
    vector<string> resultRight;
    //turn left side of the condition to expression and calculate it
    stringsLeft = infToPre.convertToStrings(condition[0]);
    resultLeft = infToPre.convertFunc(stringsLeft);
    Expression *eLeft = infToPre.turnToExppression(resultLeft);
    left = eLeft->calculate();
    //turn right side of the condition to expression and calculate it
    stringsRight = infToPre.convertToStrings(condition[2]);
    resultRight = infToPre.convertFunc(stringsRight);
    Expression *eRight = infToPre.turnToExppression(resultRight);
    right = eRight->calculate();

    //we want to check between the two parts of the condition if it is true or false, we start with >
    if (condition[1] == ">") {
        if (left > right) {
            return true;
        } else {
            return false;
        }
    }
    //we check >=
    if (condition[1] == ">=") {
        if (left >= right) {
            return true;
        } else {
            return false;
        }
    }
    //we check <
    if (condition[1] == "<") {
        if (left < right) {
            return true;
        } else {
            return false;
        }
    }
    //we check <=
    if (condition[1] == "<=") {
        if (left <= right) {
            return true;
        } else {
            return false;
        }
    }
    //we check ==
    if (condition[1] == "==") {
        if (left == right) {
            return true;
        } else {
            return false;
        }
    }
    //we check !=
    if (condition[1] == "!=") {
        if (left != right) {
            return true;
        } else {
            return false;
        }
    }
}