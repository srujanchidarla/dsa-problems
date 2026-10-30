from typing import List


class SolutionBruteForce:
    """O(n^2) time | O(1) space — count occurrences of each element."""

    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        for x in nums:
            if nums.count(x) > n // 2:
                return x
        return -1  # unreachable: majority is guaranteed to exist


class Solution:
    """O(n) time | O(1) space — Boyer-Moore majority vote."""

    def majorityElement(self, nums: List[int]) -> int:
        candidate = None
        count = 0
        for x in nums:
            if count == 0:
                candidate = x
            count += 1 if x == candidate else -1
        return candidate
