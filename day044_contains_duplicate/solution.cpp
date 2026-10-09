#include <vector>
#include <unordered_set>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(1) space — for each element, scan the rest.
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++)
            for (int j = i + 1; j < (int)nums.size(); j++)
                if (nums[i] == nums[j]) return true;
        return false;
    }
};

class Solution {
    // O(n) time | O(n) space — one pass with a set, early exit.
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return true;
            seen.insert(num);
        }
        return false;
    }
};
