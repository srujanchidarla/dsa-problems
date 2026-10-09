#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class SolutionBruteForce {
    // O(n^2 * k log k) — compare each word against every group.
    bool isAnagram(string a, string b) {
        if (a.size() != b.size()) return false;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        for (string& w : strs) {
            bool placed = false;
            for (auto& g : groups) {
                if (isAnagram(w, g[0])) {
                    g.push_back(w);
                    placed = true;
                    break;
                }
            }
            if (!placed) groups.push_back({w});
        }
        return groups;
    }
};

class Solution {
    // O(n * k log k) — sorted canonical key in a hash map.
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string& w : strs) {
            string key = w;
            sort(key.begin(), key.end());
            map[key].push_back(w);
        }
        vector<vector<string>> out;
        for (auto& [k, v] : map) out.push_back(v);
        return out;
    }
};
