#include <iostream>

using namespace std;

// Optimized (1 to N): Post-recursion print
void print_1_to_N_optimal(int n) {
    if (n == 0) {
        return;
    }
    print_1_to_N_optimal(n - 1); // Recurse first (build stack)
    cout << n << " ";           // Print after return (unwind stack)
}

// Brute Force (N to 1): Pre-recursion print
void print_N_to_1_brute(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";           // Print first (manage state before call)
    print_N_to_1_brute(n - 1);
}

void solve_print_n() {
    int N;
    if (!(cin >> N)) return;

    cout << "N to 1 (Brute): ";
    print_N_to_1_brute(N);
    cout << "\n1 to N (Optimal): ";
    print_1_to_N_optimal(N);
    cout << endl;
}

int main() {
    solve_print_n();
    return 0;
}