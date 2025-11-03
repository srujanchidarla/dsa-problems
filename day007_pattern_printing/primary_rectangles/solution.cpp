#include <iostream>

using namespace std;

// Solves both Filled and Hollow Rectangle patterns
void solve_rectangles() {
    int N, M; // N=Rows (Length L), M=Columns (Width W)

    // Read N and M (For both patterns)
    if (!(cin >> N >> M)) return;

    // --- 1. Filled Rectangle (Example: N=3, M=5) ---
    cout << "--- Filled Rectangle (" << N << "x" << M << ") ---\n";
    for (int i = 0; i < N; ++i) { // Outer loop for N rows
        for (int j = 0; j < M; ++j) { // Inner loop for M columns
            cout << "*";
        }
        cout << "\n";
    }

    // --- 2. Hollow Rectangle (Example: N=4, M=5) ---
    cout << "\n--- Hollow Rectangle (" << N << "x" << M << ") ---\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // Print '*' only if it's on the boundary (first/last row/column)
            if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
                cout << "*";
            } else {
                cout << " "; // Print space inside
            }
        }
        cout << "\n";
    }
}

int main() {
    // Note: To run both, you would need to feed input N M N' M' for the second pattern.
    // Assuming single input N M for simplicity, but the functions are complete.
    solve_rectangles(); 
    return 0;
}