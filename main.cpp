#include "ExpressionConvert.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    ExpressionConvert * convert = new ExpressionConvert();
    string expression;
    getline(cin, expression);

    if (convert->isValid(expression)) {
        cout << convert->prefixToInfix(expression) << " = ";
        cout << convert->prefixCalculator(expression) << endl;
    } else {
        cout << "Error" << endl;
    }
}