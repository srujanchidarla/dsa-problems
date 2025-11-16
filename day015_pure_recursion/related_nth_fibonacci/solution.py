import sys

class Solution:
    # Optimized: O(N) Time, O(N) Space - Memoization
    def fib_memo(self, N: int, memo={}) -> int:
        if N in memo:
            return memo[N]
        if N <= 1:
            return N
        
        # Cache the result
        result = self.fib_memo(N - 1, memo) + self.fib_memo(N - 2, memo)
        memo[N] = result
        return result

    # Brute Force: O(2^N) Time, O(N) Space - Pure Recursion
    def fib_pure_recursion(self, N: int) -> int:
        if N <= 1:
            return N
        # Exponential calculation due to overlapping subproblems
        return self.fib_pure_recursion(N - 1) + self.fib_pure_recursion(N - 2)