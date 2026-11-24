#include <algorithm>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n log n) time | O(1) space — sort, then scan for the first gap.
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int want = 1;
        for (int v : nums) {
            if (v == want) want++;
            else if (v > want) break;
        }
        return want;
    }
};

class Solution {
    // O(n) time | O(1) space — cyclic sort: value v belongs at index v - 1.
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int v = nums[i];
            if (v >= 1 && v <= n && nums[v - 1] != v) {
                swap(nums[i], nums[v - 1]);
            } else {
                i++;
            }
        }
        for (int j = 0; j < n; j++) {
            if (nums[j] != j + 1) return j + 1;
        }
        return n + 1;
    }
};
