#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(n) time | O(1) space
// Each operation preserves source[i] + source[j] → total sum is invariant.
// With n >= 2, any target with the same sum is reachable (last index as sink).
// ─────────────────────────────────────────────────────────────────────────
bool canTransform(vector<int>& source, vector<int>& target) {
    long long sourceSum = 0, targetSum = 0;

    for (int x : source) sourceSum += x;
    for (int x : target) targetSum += x;

    return sourceSum == targetSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> source(n), target(n);
        for (int& x : source) cin >> x;
        for (int& x : target) cin >> x;

        cout << (canTransform(source, target) ? "true" : "false") << "\n";
    }

    return 0;
}
