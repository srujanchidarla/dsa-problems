#include <string>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n * m^2) time — try every prefix of the shortest word, longest first.
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string shortest = strs[0];
        for (auto& w : strs) if (w.size() < shortest.size()) shortest = w;
        for (int len = (int)shortest.size(); len >= 0; len--) {
            string prefix = shortest.substr(0, len);
            bool ok = true;
            for (auto& w : strs)
                if (w.rfind(prefix, 0) != 0) { ok = false; break; }
            if (ok) return prefix;
        }
        return "";
    }
};

class Solution {
    // O(S) time | O(1) extra space — vertical scan, stop at first mismatch.
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < (int)strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < (int)strs.size(); j++) {
                if (i >= (int)strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
