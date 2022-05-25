#include "ExpressionConvert.h"

#include <string>
#include <stack>
#include <cctype>
#include <iostream>

bool ExpressionConvert::isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '*':
        case '/':
          return true;
    }
    return false;
}

bool ExpressionConvert::isValid(std::string prefix) {
    int countOperator = 0;
    int countNumber = 0;

    std::string number = "";
    bool prevNumber =  false;
    for (int i = 0; i < prefix.size(); i++) {
        if (!isOperator(prefix[i]) && !isdigit(prefix[i]) && prefix[i] != ' ') return false;

        if (isOperator(prefix[i])) countOperator++;

        else if (prefix[i] == ' ' && prevNumber) {
            // if (stoi(number) > 99) return false;
            countNumber++;
            prevNumber = false;
        } 
        
        else if (isdigit(prefix[i])) {
            number += prefix[i];
            prevNumber = true;
        }
    }
    
    if (prevNumber) countNumber++;

    if (countNumber - countOperator != 1) return false;
    return true;
}

int ExpressionConvert::operatorCalculator(int a, int b, char x) {
    switch (x) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}

int ExpressionConvert::prefixCalculator(std::string prefix) {
    std::stack<int> expression;

    int len = prefix.size();
    std::string number = "";
    bool prevNumber = false;
    for (int i = len-1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            int op1 = expression.top();
            expression.pop();
            int op2 = expression.top();
            expression.pop();

            int temp = operatorCalculator(op1, op2, prefix[i]);
            expression.push(temp);

        } else if (prefix[i] == ' ' && prevNumber){
            int temp = stoi(number);
            expression.push(temp);
            number = "";
            prevNumber = false;

        } else if (prefix[i] != ' ') {
            number = prefix[i] + number;
            prevNumber = true;
        }
    }

    return expression.top();
}

std::string ExpressionConvert::prefixToInfix(std::string prefix) {
    std::stack<std::string> expression;

    int len = prefix.size();
    std::string number = "";
    bool prevNumber = false;
    for (int i = len-1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            std::string op1 = expression.top();
            expression.pop();
            std::string op2 = expression.top();
            expression.pop();

            std::string temp = "(" + op1 + " " + prefix[i] + " " + op2 + ")";
            if (i == 0 || prefix[i] == '*' || prefix[i] == '/') temp =  op1 + " " + prefix[i] + " " + op2;

            expression.push(temp);

        } else if (prefix[i] == ' ' && prevNumber) {
            expression.push(number);
            number = "";
            prevNumber = false;

        } else if (prefix[i] != ' ') {
            number = prefix[i] + number;
            prevNumber = true;
        }
    }

   return expression.top();
}