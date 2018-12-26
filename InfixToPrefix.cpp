//
// Created by gal on 12/16/18.
//

#include "InfixToPrefix.h"

int InfixToPrefix::getPriority(string str)
{
    if (str == "-" || str == "+"){
        return 1;
    }
    else if (str == "*" || str == "/"){
        return 2;
    }
    else if (str == "^"){
        return 3;
    }
    return 0;
}


vector<string> InfixToPrefix::convertFunc(vector<string> stringInfix){
    stack<string> stack;
    stack.push("END");
    int l = stringInfix.size();
    vector<string> postfixString;
    for(int i = 0; i < l; i++)
    {
        //if it is not operator or ( ) it is a number and we push it to the stack
        if((!isOperator(stringInfix[i][0])) && (stringInfix[i] != "(") && (stringInfix[i] != ")")){
            postfixString.push_back(stringInfix[i]);
        }

        // If the scanned character is an ‘(‘, push it to the stack.
        else if(stringInfix[i] == "("){
            stack.push("(");
        }
            // If the scanned character is an ‘)’, pop and to output string from the stack
            // until an ‘(‘ is encountered.
        else if(stringInfix[i] == ")")
        {
            while(stack.top() != "END" && stack.top() != "(")
            {
                string str = stack.top();
                stack.pop();
                postfixString.push_back(str);
            }
            if(stack.top() == "(")
            {
                string str2 = stack.top();
                stack.pop();
            }
        }

            //If an operator is scanned
        else{
            while(stack.top() != "END" && getPriority(stringInfix[i]) <= getPriority(stack.top()))
            {
                string str3 = stack.top();
                stack.pop();
                postfixString.push_back(str3);
            }
            stack.push(stringInfix[i]);
        }

    }
    //Pop all the remaining elements from the stack
    while(stack.top() != "END")
    {
        string str4 = stack.top();
        stack.pop();
        postfixString.push_back(str4);
    }
    return postfixString;
}

Expression* InfixToPrefix::turnToExppression(vector<string> postfixString){
    stack<Expression*> stack;
    Expression* ex;

    for (int i = 0; i < postfixString.size(); ++i){
        if(!isOperator(postfixString[i][0])) {
            ex = new Number(stod(postfixString[i]));
            stack.push(ex);
            toBeDeleted.push_back(ex);
        }
        else {
            Expression* right = stack.top();
            stack.pop();
            Expression* left = stack.top();
            stack.pop();
            switch (postfixString[i][0]){
                case '+':
                    ex = new Plus(left,right);
                    stack.push(ex);
                    toBeDeleted.push_back(ex);
                    break;
                case '-':
                    ex = new Minus(left,right);
                    stack.push(ex);
                    toBeDeleted.push_back(ex);
                    break;
                case '/':
                    ex = new Div(left,right);
                    stack.push(ex);
                    toBeDeleted.push_back(ex);
                    break;
                case '*':
                    ex = new Mul(left,right);
                    stack.push(ex);
                    toBeDeleted.push_back(ex);
                    break;
            }
        }
    }
    Expression* result = stack.top();
    //toBeDeleted.push_back(result);
    return result;
}

  //check if it is + - / * ( )
    bool InfixToPrefix::isOperator(char c){
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){
        return true;
    }
    else{
        return false;
    }
}

//bool InfixToPrefix::isOperator(char c){
//    //check if it is - + * /
//    if (c == '-' || c == '+' || c == '*' || c == '/'){
//        return true;
//    }
//    else{
//        return false;
//    }
//}

vector<string> InfixToPrefix::convertToStrings(string str) {
    vector<string> strings;
    string num = "";
    for (int i = 0; i < str.size(); ++i) {
        if (!isOperator(str[i]) && !(to_string(str[i]) == "(") && !(to_string(str[i]) == ")")) {
            num += str[i];
        } else {
            if (num != "") {
                strings.push_back(num);
                num = "";
            }
            switch (str[i]) {
                case 40:
                    strings.push_back("(");
                    break;
                case 41:
                    strings.push_back(")");
                    break;
                case 42:
                    strings.push_back("*");
                    break;
                case 43:
                    strings.push_back("+");
                    break;
                case 45:
                    strings.push_back("-");
                    break;
                case 47:
                    strings.push_back("/");
                    break;
            }
            //strings.push_back(to_string(str[i]));
        }
    }
    if (num != "") {
        strings.push_back(num);
    }
    maps->replaceVarByValue(strings);

    string s = "";
    for (int i = 0; i < strings.size(); ++i) {
        s += strings[i];
    }

    vector<string> strings2;
    string num2 = "";
    for (int i = 0; i < s.size(); ++i) {
        if (!isOperator(s[i]) && !(to_string(s[i]) == "(") && !(to_string(s[i]) == ")")) {
            num2 += s[i];
        } else {
            if (num2 != "") {
                strings2.push_back(num2);
                num2 = "";
            }
            switch (s[i]) {
                case 40:
                    strings2.push_back("(");
                    break;
                case 41:
                    strings2.push_back(")");
                    break;
                case 42:
                    strings2.push_back("*");
                    break;
                case 43:
                    strings2.push_back("+");
                    break;
                case 45:
                    strings2.push_back("-");
                    break;
                case 47:
                    strings2.push_back("/");
                    break;
            }
            //strings.push_back(to_string(str[i]));
        }
    }
    if (num2 != "") {
        strings2.push_back(num2);
    }

    return strings2;

}