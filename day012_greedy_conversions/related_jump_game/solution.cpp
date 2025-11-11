#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Optimized: O(N) Time, O(1) Space - Backward Greedy Traversal
    bool canJump_optimal(vector<int>& nums) {
        if (nums.empty()) return false;
        
        int goal = nums.size() - 1;

        // Iterate backward
        for (int i = nums.size() - 2; i >= 0; --i) {
            // Check if current position can reach or pass the goal
            if (i + nums[i] >= goal) {
                goal = i; // Update goal
            }
        }
        
        return goal == 0;
    }

    // Brute Force: O(N^2) Time - Dynamic Programming
    bool canJump_brute(vector<int>& nums) {
        int N = nums.size();
        if (N <= 1) return true;
        
        vector<bool> memo(N, false);
        memo[N - 1] = true;

        for (int i = N - 2; i >= 0; --i) {
            int max_jump = min(i + nums[i], N - 1);
            for (int j = i + 1; j <= max_jump; ++j) {
                if (memo[j]) {
                    memo[i] = true;
                    break;
                }
            }
        }
        return memo[0];
    }
};