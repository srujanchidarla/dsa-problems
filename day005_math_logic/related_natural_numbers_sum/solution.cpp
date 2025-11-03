#include <iostream>

using namespace std;

// O(1) Time, O(1) Space - Optimal
long long sumNaturalNumbers_optimal(long long N) {
    // Use the Arithmetic Series Formula: N * (N + 1) / 2
    return N * (N + 1) / 2;
}

// O(N) Time, O(1) Space - Brute Force
long long sumNaturalNumbers_brute(long long N) {
    long long sum = 0;
    for (long long i = 1; i <= N; ++i) {
        sum += i;
    }
    return sum;
}

void solve_natural_numbers_sum() {
    long long N;
    if (!(cin >> N)) return;

    // Use optimal O(1) approach
    cout << sumNaturalNumbers_optimal(N) << endl;
}

int main() {
    solve_natural_numbers_sum();
    return 0;
}