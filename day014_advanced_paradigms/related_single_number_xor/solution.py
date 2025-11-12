import sys
from typing import List
from functools import reduce
import operator

class Solution:
    # Optimized: O(N) Time, O(1) Space - XOR Application
    def singleNumber_optimal(self, nums: List[int]) -> int:
        # XORing all elements together
        # A ^ A = 0, A ^ 0 = A. Pairs cancel out.
        return reduce(operator.xor, nums)

    # Brute Force: O(N) Time, O(N) Space - Hash Set (Fails O(1) space constraint)
    def singleNumber_brute(self, nums: List[int]) -> int:
        seen = set()
        for num in nums:
            if num in seen:
                seen.remove(num)
            else:
                seen.add(num)
        
        # The remaining element is the single number
        return seen.pop()