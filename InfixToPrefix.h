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
#include "Maps.h"

using namespace std;

class InfixToPrefix{
    Maps *maps;
    vector<Expression*> toBeDeleted;
public:
    InfixToPrefix(Maps *maps) {
        this->maps = maps;
    }

    int getPriority(string str);

    vector<string> convertFunc(vector<string> stringInfix);

    Expression* turnToExppression(vector<string> postfixString);

    bool isOperator(char c);

    vector<string> convertToStrings(string str);

    ~InfixToPrefix() {
        for (auto x : this->toBeDeleted) {
            delete(x);
        }
    }
};

#endif //INTERPRETERFLIGHT_INFIXTOPREFIX_H
