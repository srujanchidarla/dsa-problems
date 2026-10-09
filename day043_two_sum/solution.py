from typing import List


class SolutionBruteForce:
    """O(n^2) time | O(1) space — check every pair."""

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []


class Solution:
    """O(n) time | O(n) space — one pass, complement lookup."""

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}

        for index, num in enumerate(nums):
            complement = target - num

            if complement in seen:
                return [seen[complement], index]
            seen[num] = index
        return []
