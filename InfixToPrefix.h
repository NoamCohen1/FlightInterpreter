//
// Created by gal on 12/16/18.
//

#ifndef INTERPRETERFLIGHT_INFIXTOPREFIX_H
#define INTERPRETERFLIGHT_INFIXTOPREFIX_H

#include "string.h"
#include <iostream>
#include "Expression.h"
#include <vector>
#include "Expression.h"
#include <bits/stdc++.h>
#include "Number.h"
#include "Minus.h"
#include "Mul.h"
#include "Plus.h"
#include "Div.h"

using namespace std;

class InfixToPrefix{
public:
    int getPriority(string str);
    vector<string> convertFunc(vector<string> stringInfix);
    Expression* turnToExppression(vector<string> postfixString);
    bool isOperator(string s);
    vector<string> convertToStrings(string str);
};

#endif //INTERPRETERFLIGHT_INFIXTOPREFIX_H
