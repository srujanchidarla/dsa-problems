#include <string>
using namespace std;

class SolutionBruteForce {
    // O(n * m) time | O(1) space — re-scan t from the start for every character of s.
public:
    bool isSubsequence(string s, string t) {
        int last = -1;
        for (char c : s) {
            bool found = false;
            for (int j = 0; j < (int)t.size(); j++) {
                if (j > last && t[j] == c) {
                    last = j;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
};

class Solution {
    // O(n + m) time | O(1) space — two pointers, one pass.
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char ch : t) {
            if (i < (int)s.size() && s[i] == ch) i++;
        }
        return i == (int)s.size();
    }
};
