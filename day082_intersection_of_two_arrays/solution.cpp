#include <unordered_set>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n * m) time | O(n) space — for each value, linear-scan the other array.
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> out;
        for (int x : nums1) {
            for (int y : nums2) {
                if (x == y) out.insert(x);
            }
        }
        return vector<int>(out.begin(), out.end());
    }
};

class Solution {
    // O(n + m) time | O(m) space — hash set of nums2, keep matching values.
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> out;
        for (int x : nums1) {
            if (s2.count(x)) out.insert(x);
        }
        return vector<int>(out.begin(), out.end());
    }
};
