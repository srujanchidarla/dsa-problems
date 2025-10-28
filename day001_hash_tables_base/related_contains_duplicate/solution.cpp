#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    // 1. Brute Force Approach: Time O(n^2), Space O(1)
    // Compares every pair of elements.
    bool containsDuplicate_brute(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    // 2. Optimized Approach: Time O(n), Space O(n) - Hash Set
    // Uses a set for O(1) average time complexity lookups.
    bool containsDuplicate_optimized(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int num : nums) {
            // Check if the number has already been added (duplicate found)
            if (seen.count(num)) {
                return true;
            }
            // Add the current number to the set
            seen.insert(num);
        }
        return false;
    }
    
    // Default entry point (using the optimized method)
    bool containsDuplicate(std::vector<int>& nums) {
        return containsDuplicate_optimized(nums);
    }
};