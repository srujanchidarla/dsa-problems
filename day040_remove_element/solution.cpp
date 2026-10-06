#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// READ / WRITE — O(n) time | O(1) space
// Copy every non-val element forward; keeps relative order
// ─────────────────────────────────────────────────────────────────────────
int removeElementReadWrite(vector<int>& nums, int val) {
    int write = 0;

    for (int read = 0; read < (int)nums.size(); read++) {
        if (nums[read] != val) {
            nums[write++] = nums[read];
        }
    }

    return write;
}

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(n) time | O(1) space
// Swap with end: overwrite val with the last element and shrink.
// Fewer writes when val is rare (order is allowed to change).
// ─────────────────────────────────────────────────────────────────────────
int removeElementOptimized(vector<int>& nums, int val) {
    int i = 0, n = nums.size();

    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            n--;                // don't advance i — recheck the swapped-in value
        } else {
            i++;
        }
    }

    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, val;
    if (cin >> n >> val) {
        vector<int> nums(n);
        for (int& x : nums) cin >> x;

        int k = removeElementOptimized(nums, val);

        cout << k << "\n";
        for (int i = 0; i < k; i++) cout << nums[i] << (i + 1 < k ? " " : "");
        cout << "\n";
    }

    return 0;
}
