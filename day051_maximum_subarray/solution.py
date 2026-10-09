from typing import List


class SolutionBruteForce:
    """O(n^2) time | O(1) space — try every subarray."""

    def maxSubArray(self, nums: List[int]) -> int:
        best = float("-inf")
        for i in range(len(nums)):
            s = 0
            for j in range(i, len(nums)):
                s += nums[j]
                best = max(best, s)
        return int(best)


class Solution:
    """O(n) time | O(1) space — Kadane's: restart or extend."""

    def maxSubArray(self, nums: List[int]) -> int:
        cur = best = nums[0]
        for x in nums[1:]:
            cur = max(x, cur + x)
            best = max(best, cur)
        return best
