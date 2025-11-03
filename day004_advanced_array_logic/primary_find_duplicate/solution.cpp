#include <iostream>
#include <vector>
#include <algorithm> // Required for sorting

using namespace std;

// Optimized: O(N) Time, O(1) Space - Floyd's Tortoise and Hare (Cycle Detection)
int findDuplicate_optimal(vector<int>& nums) {
    if (nums.empty()) return -1;

    // Phase 1: Detect the cycle
    int slow = nums[0];
    int fast = nums[nums[0]];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    // Phase 2: Find the entry point (the duplicate number)
    // Reset slow to the start of the "linked list" (index 0)
    slow = nums[0];
    // fast remains at the meeting point from Phase 1
    
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

// Brute Force: O(N^2) Time, O(1) Space - Nested loops
int findDuplicate_brute(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (nums[i] == nums[j]) {
                return nums[i];
            }
        }
    }
    return -1; // Should not be reached based on problem constraints
}

void solve_find_duplicate() {
    int N;
    // Read N (number of elements, though actual array size is N+1)
    if (!(cin >> N)) return; 

    // The array length is N (for values up to N-1). The problem array size is n+1.
    // We adjust N to be the actual size of the input array.
    vector<int> nums(N); 
    for (int i = 0; i < N; ++i) {
        if (!(cin >> nums[i])) return;
    }

    // Use the optimized O(N) approach
    int duplicate = findDuplicate_optimal(nums);
    cout << duplicate << endl;
}

int main() {
    solve_find_duplicate();
    return 0;
}