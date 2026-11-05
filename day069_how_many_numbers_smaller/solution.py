from typing import List


class SolutionBruteForce:
    """O(n^2) time | O(1) extra space — compare every pair."""

    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        answer = []
        for i in range(len(nums)):
            count = 0
            for j in range(len(nums)):
                if nums[j] < nums[i]:
                    count += 1
            answer.append(count)
        return answer


class Solution:
    """O(n) time | O(101) space — count values, then prefix sums."""

    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        count = [0] * 101
        for v in nums:
            count[v] += 1
        smaller = [0] * 101
        running = 0
        for v in range(101):
            smaller[v] = running
            running += count[v]
        return [smaller[v] for v in nums]
