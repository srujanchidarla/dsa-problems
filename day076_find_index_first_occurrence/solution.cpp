#include <string>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n * m) time | O(1) space — try every start, compare char by char.
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n - m; i++) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }
        return -1;
    }
};

class Solution {
    // O(n + m) time | O(m) space — KMP with the prefix function (LPS).
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        // Build LPS: lps[k] = longest proper prefix of needle[0..k]
        // that is also a suffix of needle[0..k].
        vector<int> lps(needle.size(), 0);
        int length = 0, i = 1;
        while (i < (int)needle.size()) {
            if (needle[i] == needle[length]) {
                lps[i++] = ++length;
            } else if (length > 0) {
                length = lps[length - 1];
            } else {
                lps[i++] = 0;
            }
        }
        // Search: j = how much of needle is currently matched.
        int j = 0;
        i = 0;
        while (i < (int)haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == (int)needle.size()) return i - j;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return -1;
    }
};
