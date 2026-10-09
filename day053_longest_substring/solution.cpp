#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(n) space — extend from each start until a repeat.
public:
    int lengthOfLongestSubstring(string s) {
        int best = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            unordered_set<char> seen;
            for (int j = i; j < (int)s.size(); j++) {
                if (seen.count(s[j])) break;
                seen.insert(s[j]);
                best = max(best, j - i + 1);
            }
        }
        return best;
    }
};

class Solution {
    // O(n) time | O(n) space — sliding window with a set.
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int l = 0, best = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            while (window.count(s[r])) {
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);
            best = max(best, r - l + 1);
        }
        return best;
    }
};
