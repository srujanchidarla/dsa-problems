class SolutionBruteForce:
    """O(n) time | O(n) space — build a reversed copy, then copy it back."""

    def reverseString(self, s: list[str]) -> None:
        rev = s[::-1]
        s[:] = rev


class Solution:
    """O(n) time | O(1) space — two pointers swap from both ends."""

    def reverseString(self, s: list[str]) -> None:
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
