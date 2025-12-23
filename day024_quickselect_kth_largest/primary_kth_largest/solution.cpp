#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = nums[pivotIndex];
        swap(nums[pivotIndex], nums[right]);
        
        int p = left;
        for (int i = left; i < right; i++) {
            if (nums[i] >= pivot) { // Sort descending for Kth largest
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[right]);
        return p;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        int target = k - 1;

        while (true) {
            int p = partition(nums, left, right);
            if (p == target) return nums[p];
            if (p > target) right = p - 1;
            else left = p + 1;
        }
    }
};