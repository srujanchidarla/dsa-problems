#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Helper function to check if a character is alphanumeric
bool isAlphaNum(char c) {
    return isalnum(c);
}

// O(N) Time, O(1) Space - Optimal (Two Pointers with in-place filtering)
void solve_valid_palindrome_optimal() {
    string S;
    if (!getline(cin, S)) return;

    int left = 0;
    int right = S.length() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters from the left
        while (left < right && !isAlphaNum(S[left])) {
            left++;
        }
        
        // Skip non-alphanumeric characters from the right
        while (left < right && !isAlphaNum(S[right])) {
            right--;
        }

        // Check for mismatch (case-insensitive)
        if (left < right && tolower(S[left]) != tolower(S[right])) {
            cout << "NO" << endl;
            return;
        }

        // Move pointers inward
        left++;
        right--;
    }
    
    cout << "YES" << endl;
}

// O(N) Time, O(N) Space - Brute Force (Preprocessing)
void solve_valid_palindrome_brute() {
    string S;
    if (!getline(cin, S)) return;

    string filtered_s = "";
    for (char c : S) {
        if (isAlphaNum(c)) {
            filtered_s += tolower(c);
        }
    }

    string reversed_s = filtered_s;
    reverse(reversed_s.begin(), reversed_s.end());
    
    if (filtered_s == reversed_s) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    solve_valid_palindrome_optimal();
    return 0;
}