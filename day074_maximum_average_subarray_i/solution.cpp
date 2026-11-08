#include <vector>
#include <algorithm>
using namespace std;

class SolutionBruteForce {
    // O(n * k) time | O(1) space — recompute every window's sum.
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double best = -1e18;
        for (int i = 0; i + k <= (int)nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) sum += nums[j];
            best = max(best, (double)sum / k);
        }
        return best;
    }
};

class Solution {
    // O(n) time | O(1) space — sliding window sum, divide once at the end.
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int window = 0;
        for (int i = 0; i < k; i++) window += nums[i];
        int best = window;
        for (int i = k; i < (int)nums.size(); i++) {
            window += nums[i] - nums[i - k];
            best = max(best, window);
        }
        return (double)best / k;
    }
};
