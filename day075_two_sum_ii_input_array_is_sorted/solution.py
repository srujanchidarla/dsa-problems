class SolutionBruteForce:
    """O(n^2) time | O(1) space — check every pair."""

    def twoSum(self, numbers, target: int):
        n = len(numbers)
        for i in range(n):
            for j in range(i + 1, n):
                if numbers[i] + numbers[j] == target:
                    return [i + 1, j + 1]
        return []


class Solution:
    """O(n) time | O(1) space — two pointers on the sorted array."""

    def twoSum(self, numbers, target: int):
        left, right = 0, len(numbers) - 1
        while left < right:
            total = numbers[left] + numbers[right]
            if total == target:
                return [left + 1, right + 1]
            elif total < target:
                left += 1
            else:
                right -= 1
        return []
