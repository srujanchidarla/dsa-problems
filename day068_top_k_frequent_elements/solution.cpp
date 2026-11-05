#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n log n) time | O(n) space — count, then sort by frequency.
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int v : nums) freq[v]++;
        vector<int> keys;
        for (auto& p : freq) keys.push_back(p.first);
        sort(keys.begin(), keys.end(),
             [&](int a, int b) { return freq[a] > freq[b]; });
        keys.resize(k);
        return keys;
    }
};

class Solution {
    // O(n) time | O(n) space — bucket sort by frequency.
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int v : nums) freq[v]++;
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& p : freq) {
            buckets[p.second].push_back(p.first);   // frequency IS the index
        }
        vector<int> result;
        for (int count = (int)nums.size(); count >= 1 && (int)result.size() < k; count--) {
            for (int num : buckets[count]) {
                result.push_back(num);
                if ((int)result.size() == k) return result;
            }
        }
        return result;
    }
};
