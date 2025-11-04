#include <iostream>
#include <string>
#include <cctype> // for isdigit

using namespace std;

// Optimal: O(N) Time - Single Pass
void solve_digit_string() {
    string S;
    if (!getline(cin, S)) return;

    if (S.empty()) {
        cout << "NO" << endl; // Empty string is not a digit string
        return;
    }

    for (char c : S) {
        if (!isdigit(c)) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
}

// Brute Force: O(N) Time - Manual check using char limits
void solve_digit_string_brute() {
    string S;
    if (!getline(cin, S)) return;
    
    if (S.empty()) {
        cout << "NO" << endl;
        return;
    }
    
    for (char c : S) {
        if (c < '0' || c > '9') {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
}

int main() {
    solve_digit_string();
    return 0;
}