#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // Optimized: O(N) Time, O(1) Space - Dutch National Flag Algorithm
    void sortColors_optimal(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap 0 to the low region
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // 1 is in the correct place
                mid++;
            } else { // nums[mid] == 2
                // Swap 2 to the high region (Do NOT increment mid)
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

    // Brute Force: O(N log N) Time - Using standard library sort
    void sortColors_brute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};