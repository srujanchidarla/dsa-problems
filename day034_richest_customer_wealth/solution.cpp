#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// BRUTE FORCE — O(m × n) time | O(m) space
// Store every customer's wealth, then pick the max
// ─────────────────────────────────────────────────────────────────────────
int maximumWealthBruteForce(vector<vector<int>>& accounts) {
    vector<int> wealths;

    for (auto& customer : accounts) {
        int wealth = 0;
        for (int money : customer) wealth += money;
        wealths.push_back(wealth);
    }

    return *max_element(wealths.begin(), wealths.end());
}

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(m × n) time | O(1) space
// Running max — no need to store every row sum
// ─────────────────────────────────────────────────────────────────────────
int maximumWealthOptimized(vector<vector<int>>& accounts) {
    int best = 0;

    for (auto& customer : accounts) {
        int wealth = accumulate(customer.begin(), customer.end(), 0);
        best = max(best, wealth);
    }

    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (cin >> m >> n) {
        vector<vector<int>> accounts(m, vector<int>(n));
        for (auto& row : accounts)
            for (int& x : row) cin >> x;

        cout << maximumWealthOptimized(accounts) << "\n";
    }

    return 0;
}
