#include <iostream>

using namespace std;

void solve_half_diamond() {
    int N; // Size of the largest row
    
    if (!(cin >> N)) return;

    // --- 1. Increasing Half (N rows: 1 to N stars) ---
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << "\n";
    }

    // --- 2. Decreasing Half (N-1 rows: N-1 down to 1 stars) ---
    for (int i = N - 1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << "\n";
    }
}

int main() {
    solve_half_diamond();
    return 0;
}