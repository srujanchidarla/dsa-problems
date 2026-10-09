#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(1) space — try every subarray.
public:
    int maxSubArray(vector<int>& nums) {
        int best = INT_MIN;
        for (int i = 0; i < (int)nums.size(); i++) {
            int s = 0;
            for (int j = i; j < (int)nums.size(); j++) {
                s += nums[j];
                best = max(best, s);
            }
        }
        return best;
    }
};

class Solution {
    // O(n) time | O(1) space — Kadane's: restart or extend.
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0], best = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return best;
    }
};
