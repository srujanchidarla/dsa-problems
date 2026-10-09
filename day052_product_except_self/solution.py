from typing import List


class SolutionBruteForce:
    """O(n^2) time | O(1) extra space — product of all others per index."""

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        answer = [1] * n
        for i in range(n):
            for j in range(n):
                if i != j:
                    answer[i] *= nums[j]
        return answer


class Solution:
    """O(n) time | O(1) extra space — prefix pass, then suffix pass."""

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        answer = [1] * n
        prefix = 1
        for i in range(n):
            answer[i] = prefix
            prefix *= nums[i]
        suffix = 1
        for i in range(n - 1, -1, -1):
            answer[i] *= suffix
            suffix *= nums[i]
        return answer
