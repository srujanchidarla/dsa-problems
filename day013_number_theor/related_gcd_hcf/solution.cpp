#include <iostream>
#include <algorithm>

using namespace std;

// Optimal: O(log(min(A,B))) Time - Euclidean Algorithm (Recursive)
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}

// Alternative Optimal: O(log(min(A,B))) Time - Euclidean Algorithm (Iterative)
int gcd_iterative(int a, int b) {
    while (b != 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

// Brute Force: O(min(A,B)) Time
int gcd_brute(int a, int b) {
    int min_val = min(a, b);
    for (int i = min_val; i >= 1; --i) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1;
}

void solve_gcd() {
    int A, B;
    if (!(cin >> A >> B)) return;
    
    cout << "GCD: " << gcd_iterative(A, B) << endl;
}

int main() {
    solve_gcd();
    return 0;
}