#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    // Optimized: O(log N) Time, O(log N) Space - Recursive
    int sum_digits_recursive(int N) {
        N = abs(N);
        if (N == 0) {
            return 0;
        }
        return (N % 10) + sum_digits_recursive(N / 10);
    }

    // Brute Force: O(log N) Time, O(1) Space - Iterative
    int sum_digits_iterative(int N) {
        N = abs(N);
        int sum_val = 0;
        while (N > 0) {
            sum_val += N % 10;
            N /= 10;
        }
        return sum_val;
    }

    void solve() {
        int N;
        if (!(cin >> N)) return;
        cout << sum_digits_recursive(N) << endl;
    }
};