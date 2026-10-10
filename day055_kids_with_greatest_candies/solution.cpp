#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// BRUTE FORCE — O(n²) time | O(1) auxiliary space
// For each kid, compare against every other kid
// ─────────────────────────────────────────────────────────────────────────
vector<bool> kidsWithCandiesBruteForce(vector<int>& candies, int extraCandies) {
    int n = candies.size();
    vector<bool> result(n, true);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (candies[i] + extraCandies < candies[j]) {
                result[i] = false;
                break;
            }
        }
    }

    return result;
}

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(n) time | O(1) auxiliary space
// Find the max once, then one comparison per kid
// ─────────────────────────────────────────────────────────────────────────
vector<bool> kidsWithCandiesOptimized(vector<int>& candies, int extraCandies) {
    int mx = *max_element(candies.begin(), candies.end());
    vector<bool> result;
    result.reserve(candies.size());

    for (int c : candies) {
        result.push_back(c + extraCandies >= mx);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, extraCandies;
    if (cin >> n >> extraCandies) {
        vector<int> candies(n);
        for (int& x : candies) cin >> x;

        vector<bool> ans = kidsWithCandiesOptimized(candies, extraCandies);

        cout << "[";
        for (size_t i = 0; i < ans.size(); i++) {
            cout << (ans[i] ? "true" : "false") << (i + 1 < ans.size() ? "," : "");
        }
        cout << "]\n";
    }

    return 0;
}
