//
// Created by noam on 12/18/18.
//

#include "ConditionParser.h"

bool ConditionParser::isOperator(char s){
    if (s == '>' || s == '<' || s == '=' || s == '!'){
        return true;
    }
    else{
        return false;
    }
}


bool ConditionParser::checkCondition(string condition) {
    InfixToPrefix infToPre;
    vector<string> twoParts;
    bool sawCondition = false;
    string left = "";
    string right = "";
    string theOperator = "";
    vector<string> stringsConverted;
    vector<Expression*> expressions;
    for (int i = 0; i < condition.size(); ++i) {
        if ((condition[i] == '(') || (condition[i] == ')')) {
            continue;
        }
        if (isOperator(condition[i])) {
            theOperator += condition[i];
            sawCondition = true;
        } else if (!(isOperator(condition[i])) && !sawCondition) {
            left += condition[i];
        } else if (!(isOperator(condition[i])) && sawCondition) {
            right += condition[i];
        }


        //strings = infToPre.convertToStrings(condition[i]);
        //stringsConverted = infToPre.convertFunc(strings);
        Expression *e = infToPre.turnToExppression(stringsConverted);
        expressions.push_back(e);
    }

    int socketPort = (int) expressions[0]->calculate();
    int Hz = (int) expressions[1]->calculate();
}

vector<vector<string>> ConditionParser::conditionInCondition(vector<vector<string>> vectors, int i) {
    int howManyBraces = 0;
    vector<vector<string>> result;
    int j;
    for (j = i; j < vectors.size(); ++j) {
        result.push_back(vectors[j]);
        for (int k = 0; k < vectors[j].size(); ++k) {
            if (vectors[j][k] == "{") {
                howManyBraces++;
                break;
            }
        }
        if (howManyBraces != 0) {
            break;
        }
    }
    while (howManyBraces != 0) {
        for (int k = 0; k < vectors[j].size(); ++k) {
            result.push_back(vectors[j]);
            if (vectors[j][k] == "{") {
                howManyBraces++;
            }
            if (vectors[j][k] == "}") {
                howManyBraces--;
            }
        }
        j++;
    }
    return result;
}