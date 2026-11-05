from typing import List
from collections import Counter


class SolutionBruteForce:
    """O(n log n) time | O(n) space — count, then sort by frequency."""

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        ranked = sorted(freq.keys(), key=lambda x: freq[x], reverse=True)
        return ranked[:k]


class Solution:
    """O(n) time | O(n) space — bucket sort by frequency."""

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        buckets = [[] for _ in range(len(nums) + 1)]
        for num, count in freq.items():
            buckets[count].append(num)   # frequency IS the index
        result = []
        for count in range(len(nums), 0, -1):
            for num in buckets[count]:
                result.append(num)
                if len(result) == k:
                    return result
        return result
