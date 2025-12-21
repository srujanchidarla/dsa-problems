#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // O(N + K) Time, O(N + K) Space
    vector<int> countingSort(vector<int>& nums) {
        if (nums.empty()) return nums;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int range = maxVal - minVal + 1;

        vector<int> count(range, 0);
        vector<int> output(nums.size());

        // Frequency mapping
        for (int num : nums) {
            count[num - minVal]++;
        }

        // Cumulative count
        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

        // Place elements in sorted order
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[count[nums[i] - minVal] - 1] = nums[i];
            count[nums[i] - minVal]--;
        }

        return output;
    }
};