#include <string>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(1) space — check every substring, stop early at "abc".
public:
    int countValidSubstrings(string s) {
        int n = s.size(), count = 0;
        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) {
                if (end - start >= 2 && s[end - 2] == 'a'
                        && s[end - 1] == 'b' && s[end] == 'c') break;
                count++;
            }
        }
        return count;
    }
};

class Solution {
    // O(n) time | O(1) space — sliding left boundary past the last "abc".
public:
    int countValidSubstrings(string s) {
        int ans = 0, left = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            if (r >= 2 && s[r - 2] == 'a' && s[r - 1] == 'b' && s[r] == 'c') {
                left = max(left, r - 1);
            }
            ans += r - left + 1;
        }
        return ans;
    }
};
