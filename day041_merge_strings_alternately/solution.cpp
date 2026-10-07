#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(m + n) time | O(m + n) space (output)
// One index up to the longer length; append whichever chars still exist
// ─────────────────────────────────────────────────────────────────────────
string mergeAlternately(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    string result;
    result.reserve(m + n);

    for (int i = 0; i < max(m, n); i++) {
        if (i < m) result += word1[i];
        if (i < n) result += word2[i];
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word1, word2;
    if (cin >> word1 >> word2) {
        cout << mergeAlternately(word1, word2) << "\n";
    }

    return 0;
}
