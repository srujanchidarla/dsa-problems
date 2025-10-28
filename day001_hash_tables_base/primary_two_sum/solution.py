from typing import List

class Solution:
    # 1. Optimized Approach: Time O(n), Space O(n) - Dictionary/Hash Map
    def twoSum_optimized(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        
        for i, num in enumerate(nums):
            complement = target - num
            
            if complement in num_map:
                return [num_map[complement], i]
            
            num_map[num] = i
            
        return [] # Should not be reached

    # 2. Brute Force Approach: Time O(n^2), Space O(1)
    def twoSum_brute(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return [] # Should not be reached
    
    # Default entry point (use the optimized one for general use)
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        return self.twoSum_optimized(nums, target)