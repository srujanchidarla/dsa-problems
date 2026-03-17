import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(n) time | O(1) space
# Single pass — bucket each number into positive, negative, or zero
# ─────────────────────────────────────────────────────────────────────────


def distribute(arr):
    pos = 0                                     # count of positive numbers
    neg = 0                                     # count of negative numbers
    zero = 0                                     # count of zeros

    for num in arr:
        if num > 0:                              # positive bucket
            pos += 1
        elif num < 0:                            # negative bucket
            neg += 1
        else:                                    # zero bucket
            zero += 1

    return pos, neg, zero


# ── Pythonic one-liner alternative (same O(n)) ────────────────────────────
def distribute_pythonic(arr):
    pos = sum(1 for x in arr if x > 0)         # count positives
    neg = sum(1 for x in arr if x < 0)         # count negatives
    zero = sum(1 for x in arr if x == 0)        # count zeros
    return pos, neg, zero


# ── Input ─────────────────────────────────────────────────────────────────
n = int(input())
arr = list(map(int, input().split()))

pos, neg, zero = distribute(arr)
print(pos)                                       # positives
print(neg)                                       # negatives
print(zero)                                      # zeros
