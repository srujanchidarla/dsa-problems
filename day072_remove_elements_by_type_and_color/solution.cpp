#include <array>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(n) space — rescan from the start after every removal.
public:
    bool canRemoveAll(vector<int> types, vector<int> colors, vector<int> groupSize) {
        while (true) {
            bool removed = false;
            int i = 0;
            while (i < (int)types.size()) {
                int j = i;
                while (j < (int)types.size() && types[j] == types[i]
                       && colors[j] == colors[i]) j++;
                if (j - i >= groupSize[types[i]]) {
                    int k = groupSize[types[i]];
                    types.erase(types.begin() + i, types.begin() + i + k);
                    colors.erase(colors.begin() + i, colors.begin() + i + k);
                    removed = true;
                    break;
                }
                i = j;
            }
            if (!removed) return types.empty();
        }
    }
};

class Solution {
    // O(n) time | O(n) space — one pass with a stack of runs.
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        vector<array<int, 3>> st; // {type, color, count}
        for (int i = 0; i < (int)types.size(); i++) {
            int t = types[i], c = colors[i];
            if (!st.empty() && st.back()[0] == t && st.back()[1] == c) {
                st.back()[2]++;
            } else {
                st.push_back({t, c, 1});
            }
            if (st.back()[2] == groupSize[t]) st.pop_back();
        }
        return st.empty();
    }
};
