#include <iostream>

using namespace std;

// O(1) Time, O(1) Space
void performOperation_optimal(int A, int B, char op) {
    long long result; // Use long long for safer arithmetic results

    // Use switch statement for clean conditional execution
    switch (op) {
        case '+':
            result = (long long)A + B;
            break;
        case '-':
            result = (long long)A - B;
            break;
        case '*':
            result = (long long)A * B;
            break;
        case '/':
            if (B == 0) {
                cout << "Error: Division by zero" << endl;
                return;
            }
            result = (long long)A / B;
            break;
        default:
            cout << "Error: Invalid operator" << endl;
            return;
    }
    cout << result << endl;
}

// Brute Force is identical to Optimal for O(1) logic, but can be done with if/else
void performOperation_brute(int A, int B, char op) {
    long long result;

    if (op == '+') {
        result = (long long)A + B;
    } else if (op == '-') {
        result = (long long)A - B;
    } else if (op == '*') {
        result = (long long)A * B;
    } else if (op == '/') {
        if (B == 0) {
            cout << "Error: Division by zero" << endl;
            return;
        }
        result = (long long)A / B;
    } else {
        cout << "Error: Invalid operator" << endl;
        return;
    }
    cout << result << endl;
}

void solve_arithmetic_operators() {
    int A, B;
    char op;

    // Assuming input format is A B op (e.g., 5 3 +)
    if (!(cin >> A >> B >> op)) return;
    
    performOperation_optimal(A, B, op);
}

int main() {
    solve_arithmetic_operators();
    return 0;
}