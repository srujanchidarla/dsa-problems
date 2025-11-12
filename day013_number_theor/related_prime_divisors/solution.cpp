#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// O(sqrt(N)) Time, O(1) Space - Optimal Primality Check
bool isPrime_optimal(int N) {
    if (N <= 1) return false;
    if (N <= 3) return true; // 2 and 3 are prime
    
    // Check factors up to sqrt(N)
    for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

// O(N) Time, O(1) Space - Brute Force Primality Check
bool isPrime_brute(int N) {
    if (N <= 1) return false;
    for (int i = 2; i < N; ++i) { // Check up to N-1
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

// O(sqrt(N)) Time, O(sqrt(N)) Space - Optimized Divisor Printing
void printDivisors_optimal(int N) {
    if (N <= 0) return;
    vector<int> divisors;
    
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            divisors.push_back(i);
            // If i and N/i are different, add the second factor
            if (i * i != N) {
                divisors.push_back(N / i);
            }
        }
    }
    
    // Sort to print in ascending order
    sort(divisors.begin(), divisors.end());
    cout << "Divisors: ";
    for (int d : divisors) {
        cout << d << " ";
    }
    cout << endl;
}

void solve_prime_divisors() {
    int N;
    if (!(cin >> N)) return;

    cout << "Is Prime: " << (isPrime_optimal(N) ? "YES" : "NO") << endl;
    printDivisors_optimal(N);
}

int main() {
    solve_prime_divisors();
    return 0;
}