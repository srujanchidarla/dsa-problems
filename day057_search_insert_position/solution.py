from typing import List


class SolutionBruteForce:
    """O(n) time | O(1) space — first index with nums[i] >= target, else n."""

    def searchInsert(self, nums: List[int], target: int) -> int:
        for i, x in enumerate(nums):
            if x >= target:
                return i
        return len(nums)


class Solution:
    """O(log n) time | O(1) space — binary search; lo is the insert point."""

    def searchInsert(self, nums: List[int], target: int) -> int:
        lo, hi = 0, len(nums) - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                lo = mid + 1
            else:
                hi = mid - 1
        return lo
