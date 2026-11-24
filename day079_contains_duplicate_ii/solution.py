class SolutionBruteForce:
    """O(n * k) time | O(1) space — for each index, check the next k positions."""

    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, min(i + k + 1, n)):
                if nums[i] == nums[j]:
                    return True
        return False


class Solution:
    """O(n) time | O(n) space — map each value to its latest index."""

    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        last = {}
        for i, x in enumerate(nums):
            if x in last and i - last[x] <= k:
                return True
            last[x] = i
        return False
