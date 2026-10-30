from typing import List


class SolutionBruteForce:
    """O(n) time | O(n) space — convert to an int, add 1, convert back."""

    def plusOne(self, digits: List[int]) -> List[int]:
        number = int("".join(str(d) for d in digits)) + 1
        return [int(c) for c in str(number)]


class Solution:
    """O(n) time | O(1) extra space — carry from the right."""

    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits) - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            digits[i] = 0
        return [1] + digits
