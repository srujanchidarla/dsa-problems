from typing import List


class SolutionBruteForce:
    """O(n^2) time | O(1) space — count the run starting at every index."""

    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        best = 0
        for i in range(len(nums)):
            count = 0
            for j in range(i, len(nums)):
                if nums[j] == 0:
                    break
                count += 1
            best = max(best, count)
        return best


class Solution:
    """O(n) time | O(1) space — one pass, reset the run on 0."""

    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0
        best = 0
        for v in nums:
            count = count + 1 if v == 1 else 0
            best = max(best, count)
        return best
