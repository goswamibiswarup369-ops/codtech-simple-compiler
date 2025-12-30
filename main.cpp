#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluate(string exp) {
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < exp.length(); i++) {
        if (isdigit(exp[i])) {
            values.push(exp[i] - '0');
        } else {
            while (!ops.empty() &&
                   precedence(ops.top()) >= precedence(exp[i])) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                values.push(applyOp(a, b, ops.top()));
                ops.pop();
            }
            ops.push(exp[i]);
        }
    }

    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        values.push(applyOp(a, b, ops.top()));
        ops.pop();
    }

    return values.top();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;
    cout << "Result: " << evaluate(exp);
    return 0;
}