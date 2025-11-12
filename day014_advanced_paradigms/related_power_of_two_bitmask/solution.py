import sys

class Solution:
    # Optimized: O(1) Time, O(1) Space - Bitwise Trick
    def isPowerOfTwo_optimal(self, n: int) -> bool:
        # Check 1: Must be positive (e.g., 0 and negative numbers are not powers of two)
        # Check 2: N & (N - 1) clears the rightmost set bit. If only one bit was set, the result is 0.
        return n > 0 and (n & (n - 1) == 0)

    # Brute Force: O(log N) Time, O(1) Space - Repeated Division
    def isPowerOfTwo_brute(self, n: int) -> bool:
        if n <= 0:
            return False
        
        while n % 2 == 0:
            n //= 2
            
        return n == 1