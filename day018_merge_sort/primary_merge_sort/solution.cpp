#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void _merge(vector<int>& arr, int low, int mid, int high) {
        // Create temporary vector to hold sorted elements
        vector<int> temp;
        int i = low;
        int j = mid + 1;

        // 1. Compare and merge (O(N))
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        // 2. Copy remaining elements (left half)
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }

        // 3. Copy remaining elements (right half)
        while (j <= high) {
            temp.push_back(arr[j++]);
        }

        // 4. Copy back to original array
        for (int k = low; k <= high; ++k) {
            arr[k] = temp[k - low];
        }
    }

    void mergeSortRec(vector<int>& arr, int low, int high) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;
        
        // Divide and Conquer (O(log N) depth)
        mergeSortRec(arr, low, mid);
        mergeSortRec(arr, mid + 1, high);
        
        // Merge (O(N) work at each level)
        _merge(arr, low, mid, high);
    }

public:
    void mergeSort_optimal(vector<int>& nums) {
        if (nums.empty()) return;
        mergeSortRec(nums, 0, nums.size() - 1);
    }
    
    // Brute Force: Any O(N^2) sort
    void mergeSort_brute(vector<int>& nums) {
        // We defer to an elementary sort like Bubble Sort for the O(N^2) comparison.
    }
};