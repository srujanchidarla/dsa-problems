#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Optimized: O(N) Time, O(1) Space - Summation Method
long long findMissingNumber_summation(const vector<int>& nums) {
    int N = nums.size();
    
    // N is the length of the array, meaning the full range is 0 to N.
    // Calculate Expected Sum of numbers from 0 to N: N * (N + 1) / 2
    long long expected_sum = (long long)N * (N + 1) / 2;

    // Calculate Actual Sum (O(N))
    long long actual_sum = 0;
    for (int num : nums) {
        actual_sum += num;
    }

    // The difference is the missing number
    return expected_sum - actual_sum;
}

// Alternative Optimal: O(N) Time, O(1) Space - XOR Method
int findMissingNumber_xor(const vector<int>& nums) {
    int N = nums.size();
    int missing = N; // Initialize with N (the number missing from the array indices 0 to N-1)

    // XOR all indices (0 to N-1) and all array elements
    for (int i = 0; i < N; ++i) {
        missing ^= i;       // XOR with expected number (index i)
        missing ^= nums[i]; // XOR with actual number (array[i])
    }
    
    // The result is the missing number
    return missing;
}

void solve_missing_number() {
    int N;
    // Input is typically the number of elements N, followed by N elements.
    if (!(cin >> N)) return; 

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> nums[i])) return;
    }

    // Use the Summation Method (Optimal)
    long long missing_number = findMissingNumber_summation(nums);
    cout << missing_number << endl;
}

int main() {
    solve_missing_number();
    return 0;
}