class SolutionBruteForce:
    """O(n log n) time | O(1) space — sort, then scan for the first gap."""

    def firstMissingPositive(self, nums: list[int]) -> int:
        nums = sorted(nums)
        want = 1
        for v in nums:
            if v == want:
                want += 1
            elif v > want:
                break
        return want


class Solution:
    """O(n) time | O(1) space — cyclic sort: value v belongs at index v - 1."""

    def firstMissingPositive(self, nums: list[int]) -> int:
        n = len(nums)
        i = 0
        while i < n:
            v = nums[i]
            if 1 <= v <= n and nums[v - 1] != v:
                nums[i], nums[v - 1] = nums[v - 1], nums[i]
            else:
                i += 1
        for i, v in enumerate(nums):
            if v != i + 1:
                return i + 1
        return n + 1
