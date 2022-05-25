#ifndef EXPRESSION_CONVERT
#define EXPRESSION_CONVERT

#include <string>

class ExpressionConvert {
    public:
        bool isOperator(char x);
        bool isValid(std::string prefix);
        int operatorCalculator(int a, int b, char x);
        int prefixCalculator(std::string prefix);
        std::string prefixToInfix(std::string prefix);
};

#endif