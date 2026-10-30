#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n) time | O(n) space — split into x-half and y-half, then zip them.
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> xs(nums.begin(), nums.begin() + n);
        vector<int> ys(nums.begin() + n, nums.end());
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(xs[i]);
            ans.push_back(ys[i]);
        }
        return ans;
    }
};

class Solution {
    // O(n) time | O(n) space — one pass writes each element to its final slot.
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];        // x_i
            ans[2 * i + 1] = nums[i + n];  // y_i
        }
        return ans;
    }
};
