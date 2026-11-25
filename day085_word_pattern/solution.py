class SolutionBruteForce:
    """O(n^2) time | O(1) space — same letter exactly when same word, for every pair."""

    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False
        n = len(pattern)
        for i in range(n):
            for j in range(n):
                if (pattern[i] == pattern[j]) != (words[i] == words[j]):
                    return False
        return True


class Solution:
    """O(n) time | O(n) space — two maps enforce the bijection in one pass."""

    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False
        p2w, w2p = {}, {}
        for ch, w in zip(pattern, words):
            if ch in p2w and p2w[ch] != w:
                return False
            if w in w2p and w2p[w] != ch:
                return False
            p2w[ch] = w
            w2p[w] = ch
        return True
