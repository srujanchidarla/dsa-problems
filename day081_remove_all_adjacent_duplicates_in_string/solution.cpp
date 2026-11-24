#include <string>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(n) space — rescan and delete pairs until nothing changes.
public:
    string removeDuplicates(string s) {
        bool changed = true;
        while (changed) {
            changed = false;
            string out;
            size_t i = 0;
            while (i < s.size()) {
                if (i + 1 < s.size() && s[i] == s[i + 1]) {
                    i += 2;
                    changed = true;
                } else {
                    out.push_back(s[i]);
                    i++;
                }
            }
            s = out;
        }
        return s;
    }
};

class Solution {
    // O(n) time | O(n) space — stack: a matching top cancels the pair.
public:
    string removeDuplicates(string s) {
        string stack;
        for (char ch : s) {
            if (!stack.empty() && stack.back() == ch) {
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }
        return stack;
    }
};
