#include <numeric>
#include <string>
using namespace std;

class SolutionBruteForce {
    // O(n * m) time — try every divisor length, longest first.
    bool divides(const string& s, const string& t) {
        if (s.size() % t.size() != 0) return false;
        string built;
        for (size_t i = 0; i < s.size() / t.size(); i++) built += t;
        return s == built;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        int minLen = min((int)str1.size(), (int)str2.size());
        for (int len = minLen; len >= 1; len--) {
            if ((int)str1.size() % len == 0 && (int)str2.size() % len == 0) {
                string candidate = str1.substr(0, len);
                if (divides(str1, candidate) && divides(str2, candidate)) return candidate;
            }
        }
        return "";
    }
};

class Solution {
    // O(n + m) time — equal concatenations + gcd of the lengths.
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd((int)str1.size(), (int)str2.size()));
    }
};
