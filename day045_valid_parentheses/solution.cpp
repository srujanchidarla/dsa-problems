#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(n) space — repeatedly strip matching pairs.
public:
    bool isValid(string s) {
        string prev;
        do {
            prev = s;
            for (auto p : {"()", "{}", "[]"}) {
                size_t pos;
                while ((pos = s.find(p)) != string::npos) s.erase(pos, 2);
            }
        } while (prev != s);
        return s.empty();
    }
};

class Solution {
    // O(n) time | O(n) space — stack matching.
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {{')', '('}, {'}', '{'}, {']', '['}};
        for (char c : s) {
            if (!pairs.count(c)) {
                st.push(c);
            } else {
                if (st.empty() || st.top() != pairs[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
