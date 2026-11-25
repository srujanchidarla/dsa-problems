#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(1) space — same letter exactly when same word, for every pair.
public:
    bool wordPattern(string pattern, string s) {
        istringstream ss(s);
        vector<string> words;
        string w;
        while (ss >> w) words.push_back(w);
        if (pattern.size() != words.size()) return false;
        for (size_t i = 0; i < pattern.size(); i++) {
            for (size_t j = 0; j < pattern.size(); j++) {
                if ((pattern[i] == pattern[j]) != (words[i] == words[j])) return false;
            }
        }
        return true;
    }
};

class Solution {
    // O(n) time | O(n) space — two maps enforce the bijection in one pass.
public:
    bool wordPattern(string pattern, string s) {
        istringstream ss(s);
        vector<string> words;
        string w;
        while (ss >> w) words.push_back(w);
        if (pattern.size() != words.size()) return false;
        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;
        for (size_t i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            if (p2w.count(ch) && p2w[ch] != words[i]) return false;
            if (w2p.count(words[i]) && w2p[words[i]] != ch) return false;
            p2w[ch] = words[i];
            w2p[words[i]] = ch;
        }
        return true;
    }
};
