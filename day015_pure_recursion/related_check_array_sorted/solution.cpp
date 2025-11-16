#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Optimized: O(N) Time, O(N) Space - Recursive Subdivision
    bool is_sorted_recursive(const vector<int>& arr, int index) {
        // Base Case 1: Reached the end
        if (index == arr.size() - 1) {
            return true;
        }
        
        // Base Case 2 (Failure): Current pair is out of order
        if (arr[index] > arr[index + 1]) {
            return false;
        }
        
        // Recursive Step
        return is_sorted_recursive(arr, index + 1);
    }

    // Brute Force: O(N) Time, O(1) Space - Iterative
    bool is_sorted_iterative(const vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
};