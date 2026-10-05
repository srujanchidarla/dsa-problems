import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(n²) time | O(k) space
# Negating x turns S into S - 2x → valid iff S ≡ 0 or S ≡ 2x (mod k).
# Keep the set of (2x mod k) for the current window as we extend right.
# Note: Python's % already returns a non-negative result for positive k
# ─────────────────────────────────────────────────────────────────────────


def longest_subarray(nums, k):
    n, best = len(nums), 0

    for l in range(n):
        total = 0
        seen = set()                             # remainders of 2x in window

        for r in range(l, n):
            total += nums[r]                     # extend window
            seen.add((2 * nums[r]) % k)

            target = total % k
            if target == 0 or target in seen:
                best = max(best, r - l + 1)

    return best


# ── Input ─────────────────────────────────────────────────────────────────
n, k = map(int, input().split())
nums = list(map(int, input().split()))

print(longest_subarray(nums, k))
