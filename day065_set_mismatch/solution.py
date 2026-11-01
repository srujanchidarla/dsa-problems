from typing import List


class SolutionBruteForce:
    """O(n^2) time | O(1) space — count every value 1..n by re-scanning."""

    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        duplicate = missing = -1
        for x in range(1, n + 1):
            count = sum(1 for v in nums if v == x)
            if count == 2:
                duplicate = x
            elif count == 0:
                missing = x
        return [duplicate, missing]


class Solution:
    """O(n) time | O(n) space — find the duplicate with a set, the missing with sums."""

    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        seen = set()
        duplicate = -1
        for v in nums:
            if v in seen:
                duplicate = v
            seen.add(v)
        expected = n * (n + 1) // 2
        missing = expected - (sum(nums) - duplicate)
        return [duplicate, missing]
