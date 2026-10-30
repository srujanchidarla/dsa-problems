#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n) time | O(1) space — first index with nums[i] >= target, else n.
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] >= target) return i;
        return nums.size();
    }
};

class Solution {
    // O(log n) time | O(1) space — binary search; lo is the insert point.
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};
