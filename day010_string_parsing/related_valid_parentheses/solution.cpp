#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Optimized: O(N) Time, O(N) Space - Stack and Hash Map
    bool isValid_optimal(string s) {
        // Hash Map for O(1) lookup: closer -> opener
        unordered_map<char, char> mappings = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> bracket_stack;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                // Case 1: Opener -> Push to stack
                bracket_stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                // Case 2: Closer
                
                // If stack is empty (unmatched closer) or mismatch
                if (bracket_stack.empty() || bracket_stack.top() != mappings[c]) {
                    return false;
                }
                // Match found -> Pop the opener
                bracket_stack.pop();
            }
        }
        
        // Final check: The string is valid only if the stack is completely empty
        return bracket_stack.empty();
    }

    // Brute Force: O(N) Time - The stack approach is the standard linear method.
    bool isValid_brute(string s) {
        return isValid_optimal(s);
    }

    void solve() {
        string s;
        if (!getline(cin, s)) return;
        
        if (isValid_optimal(s)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
};

int main() {
    Solution().solve();
    return 0;
}