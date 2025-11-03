#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max or std::max_element
#include <limits>    // Required for numeric_limits

using namespace std;

void solve_max_element() {
    int N;
    // Read N (the number of elements in the array)
    if (!(cin >> N)) return; 

    // Read the array elements
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> nums[i])) return;
    }

    if (N == 0) return;

    // Linear Scan (O(N) Time, O(1) Extra Space)
    // Initialize max_val to the smallest possible integer value 
    // to handle cases where array elements are negative.
    int max_val = numeric_limits<int>::min();

    for (int num : nums) {
        if (num > max_val) {
            max_val = num;
        }
    }
    
    // Alternative: Use STL max_element (also O(N))
    // int max_val = *max_element(nums.begin(), nums.end());

    cout << max_val << endl;
}

int main() {
    // Note: Input reading style may vary based on platform
    solve_max_element();
    return 0;
}