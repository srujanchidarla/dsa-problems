class SolutionBruteForce:
    """O(n * m) time | O(1) space — re-scan t from the start for every character of s."""

    def isSubsequence(self, s: str, t: str) -> bool:
        last = -1
        for c in s:
            found = False
            for j in range(len(t)):
                if j > last and t[j] == c:
                    last = j
                    found = True
                    break
            if not found:
                return False
        return True


class Solution:
    """O(n + m) time | O(1) space — two pointers, one pass."""

    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0
        for ch in t:
            if i < len(s) and s[i] == ch:
                i += 1
        return i == len(s)
