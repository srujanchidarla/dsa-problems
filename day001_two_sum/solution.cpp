#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    // 1. Optimized Approach: Time O(n), Space O(n) - Hash Map
    std::vector<int> twoSum_optimized(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];
            
            if (numMap.count(complement)) {
                return {numMap.at(complement), i};
            }
            
            numMap[nums[i]] = i;
        }
        return {}; // Should not be reached
    }

    // 2. Brute Force Approach: Time O(n^2), Space O(1)
    std::vector<int> twoSum_brute(std::vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // Should not be reached
    }
    
    // Default entry point (use the optimized one for submissions)
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        return twoSum_optimized(nums, target);
    }
};