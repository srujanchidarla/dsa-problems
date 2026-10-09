#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class SolutionBruteForce {
    // O(n) time | O(n) space — filter, then compare with reverse.
public:
    bool isPalindrome(string s) {
        string f;
        for (char c : s) {
            if (isalnum(c)) f += tolower(c);
        }
        string r = f;
        reverse(r.begin(), r.end());
        return f == r;
    }
};

class Solution {
    // O(n) time | O(1) space — two pointers inward.
public:
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (j > i && !isalnum(s[j])) j--;
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
