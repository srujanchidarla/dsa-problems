from typing import List


class SolutionBruteForce:
    """O(n^2) time | O(1) space — for each element, scan the rest."""

    def containsDuplicate(self, nums: List[int]) -> bool:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    return True
        return False


class Solution:
    """O(n) time | O(n) space — one pass with a set, early exit."""

    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False
