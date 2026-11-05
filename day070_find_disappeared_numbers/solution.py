from typing import List


class SolutionBruteForce:
    """O(n^2) time | O(1) extra space — check every value 1..n by scanning."""

    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        answer = []
        for x in range(1, len(nums) + 1):
            found = False
            for v in nums:
                if v == x:
                    found = True
                    break
            if not found:
                answer.append(x)
        return answer


class Solution:
    """O(n) time | O(1) extra space — mark seen values by flipping signs."""

    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for v in nums:
            i = abs(v) - 1
            if nums[i] > 0:
                nums[i] = -nums[i]   # value (i + 1) is present
        return [i + 1 for i in range(len(nums)) if nums[i] > 0]
