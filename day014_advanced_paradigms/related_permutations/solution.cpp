#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
private:
    vector<vector<int>> results;

    // Helper for Optimal: Backtracking with Visited Array
    void backtrack(const vector<int>& nums, vector<int>& current_permutation, vector<bool>& visited) {
        if (current_permutation.size() == nums.size()) {
            results.push_back(current_permutation);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                // 1. Choose
                visited[i] = true;
                current_permutation.push_back(nums[i]);
                
                // 2. Recurse
                backtrack(nums, current_permutation, visited);
                
                // 3. Backtrack
                current_permutation.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    // Optimized: O(N * N!) Time, O(N * N!) Space
    vector<vector<int>> permutations_optimal(const vector<int>& nums) {
        results.clear();
        vector<int> current_permutation;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, current_permutation, visited);
        return results;
    }
    
    // Brute Force: O(N * N!) - Fixed Complexity
    vector<vector<int>> permutations_brute(const vector<int>& nums) {
        // The swap method is an alternative O(N*N!) solution
        vector<vector<int>> res;
        vector<int> current_nums = nums;
        
        function<void(int)> permute = 
            [&](int start) {
            if (start == current_nums.size()) {
                res.push_back(current_nums);
                return;
            }
            
            for (int i = start; i < current_nums.size(); ++i) {
                swap(current_nums[start], current_nums[i]);
                permute(start + 1);
                swap(current_nums[start], current_nums[i]); // Backtrack via swap
            }
        };
        permute(0);
        return res;
    }
};