import sys
from itertools import zip_longest

# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(m + n) time | O(m + n) space (output)
# One index up to the longer length; append whichever chars still exist
# ─────────────────────────────────────────────────────────────────────────


def merge_alternately(word1, word2):
    m, n = len(word1), len(word2)
    result = []

    for i in range(max(m, n)):
        if i < m:
            result.append(word1[i])              # from word1 first
        if i < n:
            result.append(word2[i])              # then word2

    return "".join(result)


# ── Pythonic alternative (same complexity) ───────────────────────────────
def merge_alternately_pythonic(word1, word2):
    return "".join(a + b for a, b in zip_longest(word1, word2, fillvalue=""))


# ── Input ─────────────────────────────────────────────────────────────────
word1, word2 = sys.stdin.read().split()
print(merge_alternately(word1, word2))
