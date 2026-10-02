#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// BRUTE FORCE — O(n) time | O(n) space
// Copy unique values into a temp array, then write back
// ─────────────────────────────────────────────────────────────────────────
int removeDuplicatesBruteForce(vector<int>& nums) {
    vector<int> unique;

    for (int x : nums) {
        if (unique.empty() || unique.back() != x) unique.push_back(x);
    }

    for (size_t i = 0; i < unique.size(); i++) nums[i] = unique[i];

    return unique.size();
}

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(n) time | O(1) space
// Two pointers: read scans, write marks the next unique slot
// ─────────────────────────────────────────────────────────────────────────
int removeDuplicatesOptimized(vector<int>& nums) {
    int write = 1;

    for (int read = 1; read < (int)nums.size(); read++) {
        if (nums[read] != nums[write - 1]) {
            nums[write++] = nums[read];
        }
    }

    return write;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> nums(n);
        for (int& x : nums) cin >> x;

        int k = removeDuplicatesOptimized(nums);

        cout << k << "\n";
        for (int i = 0; i < k; i++) cout << nums[i] << (i + 1 < k ? " " : "\n");
    }

    return 0;
}
