class SolutionBruteForce:
    """O(n) time | O(n) space — split into words and take the last one."""

    def lengthOfLastWord(self, s: str) -> int:
        return len(s.split()[-1])


class Solution:
    """O(n) time | O(1) space — walk backwards past trailing spaces, then count."""

    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1
        while i >= 0 and s[i] == " ":
            i -= 1
        length = 0
        while i >= 0 and s[i] != " ":
            length += 1
            i -= 1
        return length
