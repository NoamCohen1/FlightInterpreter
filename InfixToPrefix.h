//
// Created by gal on 12/16/18.
//

#ifndef INTERPRETERFLIGHT_INFIXTOPREFIX_H
#define INTERPRETERFLIGHT_INFIXTOPREFIX_H

#include "string.h"
#include <iostream>
#include "Expression.h"
#include <vector>

using namespace std;

class InfixToPrefix{
public:
    int getPriority(string str);
    vector<string> convertFunc(vector<string> stringInfix);
    Expression* turnToExppression(vector<string> postfixString);
    bool isOperator(string s);
    };

#endif //INTERPRETERFLIGHT_INFIXTOPREFIX_H
