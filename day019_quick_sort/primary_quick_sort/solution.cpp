#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    int _partition(vector<int>& nums, int low, int high) {
        // Lomuto Partition Scheme
        int pivot = nums[high];
        int i = low - 1; 

        for (int j = low; j < high; ++j) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    void quickSortRec(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pi = _partition(nums, low, high);
            quickSortRec(nums, low, pi - 1);
            quickSortRec(nums, pi + 1, high);
        }
    }

public:
    void quickSort_optimal(vector<int>& nums) {
        if (nums.empty()) return;
        quickSortRec(nums, 0, nums.size() - 1);
    }
    
    void quickSort_brute(vector<int>& nums) {
        // Brute force is the same implementation, but applied to worst-case input.
        quickSort_optimal(nums);
    }
};