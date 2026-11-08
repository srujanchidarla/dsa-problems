class SolutionBruteForce:
    """O(n * k) time | O(1) space — recompute every window's sum."""

    def findMaxAverage(self, nums, k: int) -> float:
        best = float("-inf")
        for i in range(len(nums) - k + 1):
            best = max(best, sum(nums[i:i + k]) / k)
        return best


class Solution:
    """O(n) time | O(1) space — sliding window sum, divide once at the end."""

    def findMaxAverage(self, nums, k: int) -> float:
        window = sum(nums[:k])
        best = window
        for i in range(k, len(nums)):
            window += nums[i] - nums[i - k]
            best = max(best, window)
        return best / k
