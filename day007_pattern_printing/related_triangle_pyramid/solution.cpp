#include <iostream>

using namespace std;

void solve_triangle_pyramid() {
    int N; // Size of the pattern
    
    if (!(cin >> N)) return;

    // --- 1. Right-Angled Triangle Pattern (Example N=5) ---
    cout << "--- Right-Angled Triangle (" << N << ") ---\n";
    for (int i = 1; i <= N; ++i) {
        // Inner loop runs 'i' times (1, 2, 3, ...)
        for (int j = 1; j <= i; ++j) {
            cout << "* "; // Note: The example uses a space after the asterisk
        }
        cout << "\n";
    }

    // --- 2. Pyramid Pattern (Isosceles/Centered) (Example N=5) ---
    cout << "\n--- Pyramid Pattern (" << N << ") ---\n";
    for (int i = 0; i < N; ++i) {
        // Loop 1: Print leading spaces (N - 1 - i spaces)
        for (int j = 0; j < N - 1 - i; ++j) {
            cout << " ";
        }
        
        // Loop 2: Print stars (2 * i + 1 stars)
        for (int j = 0; j < 2 * i + 1; ++j) {
            cout << "*";
        }
        
        cout << "\n";
    }
}

int main() {
    solve_triangle_pyramid();
    return 0;
}