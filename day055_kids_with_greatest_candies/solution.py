import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(n) time | O(1) auxiliary space
# Find the max once, then one comparison per kid
# ─────────────────────────────────────────────────────────────────────────


def kids_with_candies(candies, extra_candies):
    mx = max(candies)                            # current greatest
    return [c + extra_candies >= mx for c in candies]  # ties count


# ── Input ─────────────────────────────────────────────────────────────────
n, extra_candies = map(int, input().split())
candies = list(map(int, input().split()))

ans = kids_with_candies(candies, extra_candies)
print("[" + ",".join("true" if x else "false" for x in ans) + "]")
