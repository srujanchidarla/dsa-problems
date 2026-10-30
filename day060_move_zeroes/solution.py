from typing import List


class SolutionBruteForce:
    """O(n) time | O(n) space — collect non-zeroes, then pad with zeroes."""

    def moveZeroes(self, nums: List[int]) -> None:
        kept = [x for x in nums if x != 0]
        kept += [0] * (len(nums) - len(kept))
        nums[:] = kept


class Solution:
    """O(n) time | O(1) space — read/write pointers, fill tail with 0."""

    def moveZeroes(self, nums: List[int]) -> None:
        write = 0
        for read in range(len(nums)):
            if nums[read] != 0:
                nums[write] = nums[read]
                write += 1
        for i in range(write, len(nums)):
            nums[i] = 0
