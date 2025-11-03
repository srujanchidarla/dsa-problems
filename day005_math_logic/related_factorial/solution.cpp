#include <iostream>

using namespace std;

// O(N) Time, O(1) Space - Iterative (Optimal)
long long calculateFactorial_iterative(int N) {
    if (N < 0) return -1; // Handle invalid input
    if (N == 0 || N == 1) return 1;

    long long result = 1;
    for (int i = 2; i <= N; ++i) {
        result *= i;
        // NOTE: In a real system, you would check for overflow here.
    }
    return result;
}

// O(N) Time, O(N) Stack Space - Recursive (Brute Force/Alternative)
long long calculateFactorial_recursive(int N) {
    if (N < 0) return -1;
    if (N == 0 || N == 1) return 1;
    
    // Recursive call: N * (N-1)!
    return (long long)N * calculateFactorial_recursive(N - 1);
}

void solve_factorial() {
    int N;
    if (!(cin >> N)) return;

    // Use the iterative O(N) approach
    cout << calculateFactorial_iterative(N) << endl;
}

int main() {
    solve_factorial();
    return 0;
}