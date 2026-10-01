#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// BRUTE FORCE — O(log n) time | O(1) space
// Simulate exactly what the problem says
// ─────────────────────────────────────────────────────────────────────────
int numberOfStepsBruteForce(int num) {
    int steps = 0;

    while (num > 0) {
        if (num % 2 == 0) num /= 2;
        else              num -= 1;
        steps++;
    }

    return steps;
}

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(1) time | O(1) space
// Each 1-bit = one subtract, each bit below the MSB = one divide
// ─────────────────────────────────────────────────────────────────────────
int numberOfStepsOptimized(int num) {
    if (num == 0) return 0;

    int ones      = __builtin_popcount(num);
    int bitLength = 32 - __builtin_clz(num);

    return ones + bitLength - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    if (cin >> num) {
        cout << numberOfStepsOptimized(num) << "\n";
    }

    return 0;
}
