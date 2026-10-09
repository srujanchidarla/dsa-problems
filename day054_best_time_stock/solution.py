from typing import List


class SolutionBruteForce:
    """O(n^2) time | O(1) space — try every buy/sell pair."""

    def maxProfit(self, prices: List[int]) -> int:
        best = 0
        for buy in range(len(prices)):
            for sell in range(buy + 1, len(prices)):
                best = max(best, prices[sell] - prices[buy])
        return best


class Solution:
    """O(n) time | O(1) space — track cheapest day, best profit."""

    def maxProfit(self, prices: List[int]) -> int:
        l, best = 0, 0
        for r in range(1, len(prices)):
            if prices[r] > prices[l]:
                best = max(best, prices[r] - prices[l])
            else:
                l = r
        return best
