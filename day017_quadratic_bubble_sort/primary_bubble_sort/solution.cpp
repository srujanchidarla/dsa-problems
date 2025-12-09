#include <vector>
#include <iostream>
#include <algorithm> // for swap

using namespace std;

class Solution {
public:
    // Optimized: O(N^2) Time (Worst/Avg), O(N) Time (Best), O(1) Space
    void bubbleSort_optimized(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            bool swapped = false;
            // Inner loop runs up to N-i-1
            for (int j = 0; j < N - 1 - i; ++j) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
            // Optimization: If no swaps occurred, the array is sorted
            if (!swapped) {
                break;
            }
        }
    }

    // Brute Force: O(N^2) Time (Always) - No early exit
    void bubbleSort_brute(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            // Outer loop always runs N times
            for (int j = 0; j < N - 1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};