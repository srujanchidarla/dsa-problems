import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(n) time | O(1) space
# Operation preserves source[i] + source[j] → total sum is invariant.
# With n >= 2, any target with the same sum is reachable (last index as sink).
# ─────────────────────────────────────────────────────────────────────────


def can_transform(source, target):
    return sum(source) == sum(target)            # Python ints never overflow


# ── Input ─────────────────────────────────────────────────────────────────
n = int(input())
source = list(map(int, input().split()))
target = list(map(int, input().split()))

print("true" if can_transform(source, target) else "false")
