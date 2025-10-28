from typing import List

class Solution:

    # 1. Brute Force Approach: Time O(n^2), Space O(1)
    # Compares every pair of elements.
    def containsDuplicate_brute(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] == nums[j]:
                    return True
        return False

    # 2. Optimized Approach: Time O(n), Space O(n) - Set
    # Uses a set for O(1) average time complexity lookups.
    def containsDuplicate_optimized(self, nums: List[int]) -> bool:
        seen = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False
    
    # Pythonic One-Liner (O(n) Time/Space)
    def containsDuplicate_pythonic(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))

    # Default entry point (using the optimized method)
    def containsDuplicate(self, nums: List[int]) -> bool:
        return self.containsDuplicate_optimized(nums)