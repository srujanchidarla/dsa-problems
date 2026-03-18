import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(n) time | O(1) space
# Single pass — add each number to odd or even accumulator
# Note: In Python, -3 % 2 = 1 (not -1 like Java) so negatives work correctly
# ─────────────────────────────────────────────────────────────────────────


def odd_even_sum(arr):
    odd_sum = 0                                 # sum of all odd numbers
    even_sum = 0                                 # sum of all even numbers

    for num in arr:
        if num % 2 != 0:                         # num % 2 is 1 or -1 for odds
            odd_sum += num                      # odd bucket
        else:
            even_sum += num                      # even bucket

    return odd_sum, even_sum


# ── Pythonic alternative (same O(n)) ─────────────────────────────────────
def odd_even_sum_pythonic(arr):
    odd_sum = sum(x for x in arr if x % 2 != 0)
    even_sum = sum(x for x in arr if x % 2 == 0)
    return odd_sum, even_sum


# ── Input ─────────────────────────────────────────────────────────────────
n = int(input())
arr = list(map(int, input().split()))

odd_sum, even_sum = odd_even_sum(arr)
print(odd_sum)                                   # sum of odds
print(even_sum)                                  # sum of evens
