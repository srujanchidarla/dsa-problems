import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(1) time | O(1) space
# 0 if same square, 1 if same row/col/diagonal, else 2
# ─────────────────────────────────────────────────────────────────────────


def min_queen_moves(source, target):
    dr = abs(source[0] - target[0])              # row distance
    dc = abs(source[1] - target[1])              # column distance

    if dr == 0 and dc == 0:
        return 0                                 # already there
    if dr == 0 or dc == 0 or dr == dc:
        return 1                                 # row / column / diagonal
    return 2                                     # row move + column move


# ── Input ─────────────────────────────────────────────────────────────────
sr, sc, tr, tc = map(int, sys.stdin.read().split())
print(min_queen_moves([sr, sc], [tr, tc]))
