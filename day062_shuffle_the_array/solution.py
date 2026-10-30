from typing import List


class SolutionBruteForce:
    """O(n) time | O(n) space — split into x-half and y-half, then zip them."""

    def shuffle(self, nums: List[int], n: int) -> List[int]:
        xs = nums[:n]
        ys = nums[n:]
        ans: List[int] = []
        for x, y in zip(xs, ys):
            ans.append(x)
            ans.append(y)
        return ans


class Solution:
    """O(n) time | O(n) space — one pass writes each element to its final slot."""

    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ans = [0] * (2 * n)
        for i in range(n):
            ans[2 * i] = nums[i]        # x_i
            ans[2 * i + 1] = nums[i + n]  # y_i
        return ans
