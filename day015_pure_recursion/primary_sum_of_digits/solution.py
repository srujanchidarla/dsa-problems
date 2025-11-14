import sys

class Solution:
    # Optimized: O(log N) Time, O(log N) Space - Recursive
    def sum_digits_recursive(self, N: int) -> int:
        N = abs(N)
        if N == 0:
            return 0
        # Tail Recursion: Sum(N) = (N % 10) + Sum(N // 10)
        return (N % 10) + self.sum_digits_recursive(N // 10)

    # Brute Force: O(log N) Time, O(1) Space - Iterative
    def sum_digits_iterative(self, N: int) -> int:
        N = abs(N)
        sum_val = 0
        while N > 0:
            sum_val += N % 10
            N //= 10
        return sum_val

    def solve(self):
        try:
            N = int(sys.stdin.readline().strip())
        except:
            return
        print(self.sum_digits_recursive(N))