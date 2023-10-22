#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int evaluateRPN(string expression) {
    stack<int> stack;
    istringstream iss(expression);
    string symbol;

    while (iss >> symbol) {
        if (symbol != "+" && symbol != "-" && symbol != "*") {
            stack.push(stoi(symbol));
        } else {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            if (symbol == "+") {
                stack.push(operand1 + operand2);
            } else if (symbol == "-") {
                stack.push(operand1 - operand2);
            } else if (symbol == "*") {
                stack.push(operand1 * operand2);
            }
        }
    }

    return stack.top();
}

int main() {
    string expression;
    getline(cin, expression);

    int result = evaluateRPN(expression);
    cout << result << endl;

    return 0;
}
