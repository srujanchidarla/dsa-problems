#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Optimized: O(N) Time, O(N) Space - Memoization
    int fib_memo(int N, vector<int>& memo) {
        if (N <= 1) {
            return N;
        }
        if (memo[N] != -1) {
            return memo[N];
        }
        
        // Cache the result
        memo[N] = fib_memo(N - 1, memo) + fib_memo(N - 2, memo);
        return memo[N];
    }

    // Brute Force: O(2^N) Time, O(N) Space - Pure Recursion
    int fib_pure_recursion(int N) {
        if (N <= 1) {
            return N;
        }
        return fib_pure_recursion(N - 1) + fib_pure_recursion(N - 2);
    }
    
    void solve() {
        int N;
        if (!(cin >> N)) return;
        
        // Initialize memoization table (size N+1)
        vector<int> memo(N + 1, -1); 
        cout << "Fib(N): " << fib_memo(N, memo) << endl;
    }
};