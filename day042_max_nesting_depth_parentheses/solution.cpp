#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// BRUTE FORCE — O(n) time | O(n) space
// Explicit stack; depth = stack size
// ─────────────────────────────────────────────────────────────────────────
int maxDepthBruteForce(string s) {
    stack<char> st;
    int best = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
            best = max(best, (int)st.size());
        } else if (c == ')') {
            st.pop();
        }
    }

    return best;
}

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(n) time | O(1) space
// Only one bracket type → a counter replaces the stack
// ─────────────────────────────────────────────────────────────────────────
int maxDepthOptimized(string s) {
    int depth = 0, best = 0;

    for (char c : s) {
        if (c == '(') {
            depth++;
            best = max(best, depth);
        } else if (c == ')') {
            depth--;
        }
    }

    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        cout << maxDepthOptimized(s) << "\n";
    }

    return 0;
}
