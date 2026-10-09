class SolutionBruteForce:
    """O(n log n) time | O(n) space — sort both and compare."""

    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)


class Solution:
    """O(n) time | O(1) space — single frequency array."""

    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        count = [0] * 26
        for c in s:
            count[ord(c) - ord("a")] += 1
        for c in t:
            count[ord(c) - ord("a")] -= 1
        return all(v == 0 for v in count)
