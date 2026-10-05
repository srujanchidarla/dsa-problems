#include <bits/stdc++.h>
using namespace std;

static inline int modK(long long v, int k) { return (int)(((v % k) + k) % k); }

// ─────────────────────────────────────────────────────────────────────────
// BRUTE FORCE — O(n³) time | O(1) space
// For every subarray, try "no negation" and each possible single negation
// ─────────────────────────────────────────────────────────────────────────
int longestSubarrayBruteForce(vector<int>& nums, int k) {
    int n = nums.size(), best = 0;

    for (int l = 0; l < n; l++) {
        long long sum = 0;
        for (int r = l; r < n; r++) {
            sum += nums[r];

            bool valid = modK(sum, k) == 0;
            for (int i = l; i <= r && !valid; i++) {
                if (modK(sum - 2LL * nums[i], k) == 0) valid = true;
            }

            if (valid) best = max(best, r - l + 1);
        }
    }

    return best;
}

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(n²) time | O(k) space
// Negating x turns S into S - 2x → valid iff S ≡ 0 or S ≡ 2x (mod k).
// Keep the set of (2x mod k) for the current window as we extend right.
// ─────────────────────────────────────────────────────────────────────────
int longestSubarrayOptimized(vector<int>& nums, int k) {
    int n = nums.size(), best = 0;
    vector<char> seen(k, 0);

    for (int l = 0; l < n; l++) {
        long long sum = 0;

        for (int r = l; r < n; r++) {
            sum += nums[r];
            seen[modK(2LL * nums[r], k)] = 1;

            int target = modK(sum, k);
            if (target == 0 || seen[target]) best = max(best, r - l + 1);
        }

        // reset only what we touched → O(n) instead of O(k)
        for (int r = l; r < n; r++) seen[modK(2LL * nums[r], k)] = 0;
    }

    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (cin >> n >> k) {
        vector<int> nums(n);
        for (int& x : nums) cin >> x;

        cout << longestSubarrayOptimized(nums, k) << "\n";
    }

    return 0;
}
