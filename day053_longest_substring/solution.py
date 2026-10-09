class SolutionBruteForce:
    """O(n^2) time | O(n) space — extend from each start until a repeat."""

    def lengthOfLongestSubstring(self, s: str) -> int:
        best = 0
        for i in range(len(s)):
            seen = set()
            for j in range(i, len(s)):
                if s[j] in seen:
                    break
                seen.add(s[j])
                best = max(best, j - i + 1)
        return best


class Solution:
    """O(n) time | O(n) space — sliding window with a set."""

    def lengthOfLongestSubstring(self, s: str) -> int:
        window = set()
        l = 0
        best = 0
        for r in range(len(s)):
            while s[r] in window:
                window.remove(s[l])
                l += 1
            window.add(s[r])
            best = max(best, r - l + 1)
        return best
