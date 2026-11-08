class SolutionBruteForce:
    """O(n^2) time | O(1) space — check every substring, stop early at "abc"."""

    def countValidSubstrings(self, s: str) -> int:
        n = len(s)
        count = 0
        for start in range(n):
            for end in range(start, n):
                if end - start >= 2 and s[end - 2:end + 1] == "abc":
                    break
                count += 1
        return count


class Solution:
    """O(n) time | O(1) space — sliding left boundary past the last "abc"."""

    def countValidSubstrings(self, s: str) -> int:
        ans = 0
        left = 0
        for r in range(len(s)):
            if r >= 2 and s[r - 2:r + 1] == "abc":
                left = max(left, r - 1)
            ans += r - left + 1
        return ans
