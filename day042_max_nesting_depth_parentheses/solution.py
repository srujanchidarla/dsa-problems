import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(n) time | O(1) space
# Only one bracket type → a counter replaces the stack
# ─────────────────────────────────────────────────────────────────────────


def max_depth(s):
    depth = 0                                    # current nesting level
    best = 0                                     # deepest level seen

    for c in s:
        if c == "(":
            depth += 1                           # go deeper
            best = max(best, depth)
        elif c == ")":
            depth -= 1                           # come back up

    return best


# ── Input ─────────────────────────────────────────────────────────────────
s = input().strip()
print(max_depth(s))
