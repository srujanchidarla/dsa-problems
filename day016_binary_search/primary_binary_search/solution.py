from typing import List

class Solution:
    # Optimized: O(log N) Time, O(1) Space - Iterative
    def search_iterative(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        
        while left <= right:
            # Use left + (right - left) // 2 to prevent overflow
            mid = left + (right - left) // 2
            
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1  # Target is in the right half
            else:
                right = mid - 1 # Target is in the left half
                
        return -1
    
    # Brute Force: O(N) Time
    def search_brute(self, nums: List[int], target: int) -> int:
        for i, num in enumerate(nums):
            if num == target:
                return i
        return -1