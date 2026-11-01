#include <algorithm>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(1) space — count the run starting at every index.
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int best = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int count = 0;
            for (int j = i; j < (int)nums.size(); j++) {
                if (nums[j] == 0) break;
                count++;
            }
            best = max(best, count);
        }
        return best;
    }
};

class Solution {
    // O(n) time | O(1) space — one pass, reset the run on 0.
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, best = 0;
        for (int v : nums) {
            count = v == 1 ? count + 1 : 0;
            best = max(best, count);
        }
        return best;
    }
};
