import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# BRUTE FORCE — O(n²) time | O(1) auxiliary space
# For each kid, compare against every other kid
# ─────────────────────────────────────────────────────────────────────────


def kids_with_candies_brute_force(candies, extra_candies):
    result = []
    for c in candies:
        ok = True
        for other in candies:
            if c + extra_candies < other:  # someone still has more → not greatest
                ok = False
                break
        result.append(ok)
    return result


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
