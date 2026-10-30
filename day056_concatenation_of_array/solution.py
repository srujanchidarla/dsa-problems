from typing import List


class SolutionBruteForce:
    """O(n) time | O(n) space — fill ans[i] = nums[i % n] for 2n positions."""

    def getConcatenation(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * (2 * n)
        for i in range(2 * n):
            ans[i] = nums[i % n]
        return ans


class Solution:
    """O(n) time | O(n) space — one pass fills both halves."""

    def getConcatenation(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * (2 * n)
        for i in range(n):
            ans[i] = nums[i]
            ans[i + n] = nums[i]
        return ans
