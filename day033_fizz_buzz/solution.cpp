#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// BRUTE FORCE — O(n) time | O(1) auxiliary space
// Direct modulo evaluation with strict ordering for LCM (15)
// ─────────────────────────────────────────────────────────────────────────
vector<string> fizzBuzzBruteForce(int n) {
    vector<string> result;
    result.reserve(n);

    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            result.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
            result.push_back("Fizz");
        } else if (i % 5 == 0) {
            result.push_back("Buzz");
        } else {
            result.push_back(to_string(i));
        }
    }

    return result;
}

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(n) time | O(1) auxiliary space
// Concatenation: avoids hardcoding LCM combinations, scales to more rules
// ─────────────────────────────────────────────────────────────────────────
vector<string> fizzBuzzOptimized(int n) {
    vector<string> result;
    result.reserve(n);

    for (int i = 1; i <= n; i++) {
        string current = "";

        if (i % 3 == 0) current += "Fizz";
        if (i % 5 == 0) current += "Buzz";

        if (current.empty()) {
            current = to_string(i);
        }

        result.push_back(move(current));
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<string> ans = fizzBuzzOptimized(n);

        cout << "[";
        for (size_t i = 0; i < ans.size(); i++) {
            cout << "\"" << ans[i] << "\"" << (i + 1 < ans.size() ? "," : "");
        }
        cout << "]\n";
    }

    return 0;
}