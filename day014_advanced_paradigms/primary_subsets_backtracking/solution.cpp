#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> results;

    // Helper for Optimal: Backtracking/DFS
    void backtrack(const vector<int>& nums, int index, vector<int>& current_subset) {
        // Base Case: Add the current subset to results
        results.push_back(current_subset);

        for (int i = index; i < nums.size(); ++i) {
            // 1. Choose
            current_subset.push_back(nums[i]);
            
            // 2. Recurse (Note: recurse with i + 1)
            backtrack(nums, i + 1, current_subset);
            
            // 3. Backtrack
            current_subset.pop_back();
        }
    }

public:
    // Optimized: O(N * 2^N) Time, O(N * 2^N) Space - Backtracking
    vector<vector<int>> subsets_optimal(const vector<int>& nums) {
        results.clear();
        vector<int> current_subset;
        backtrack(nums, 0, current_subset);
        return results;
    }

    // Alternative Optimal: O(N * 2^N) Time, O(N * 2^N) Space - Bit Manipulation
    vector<vector<int>> subsets_bit_manipulation(const vector<int>& nums) {
        vector<vector<int>> bit_results;
        int N = nums.size();
        int total_subsets = 1 << N; // 2^N

        for (int i = 0; i < total_subsets; ++i) {
            vector<int> subset;
            for (int j = 0; j < N; ++j) {
                // Check if the j-th bit is set in the mask i
                if ((i >> j) & 1) {
                    subset.push_back(nums[j]);
                }
            }
            bit_results.push_back(subset);
        }
        return bit_results;
    }
};