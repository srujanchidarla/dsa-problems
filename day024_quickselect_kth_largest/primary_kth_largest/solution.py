import random
from typing import List

class Solution:
    # Optimized: O(N) Avg Time, O(1) Space
    def findKthLargest(self, nums: List[int], k: int) -> int:
        target = k - 1 # Index in 0-based sorted array
        
        def quickselect(left, right):
            # Randomized pivot to avoid O(N^2) worst case
            pivot_idx = random.randint(left, right)
            nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
            
            pivot = nums[right]
            p = left
            # Partition: elements > pivot move to the left
            for i in range(left, right):
                if nums[i] >= pivot:
                    nums[i], nums[p] = nums[p], nums[i]
                    p += 1
            
            nums[p], nums[right] = nums[right], nums[p]
            
            if p == target:
                return nums[p]
            elif p > target:
                return quickselect(left, p - 1)
            else:
                return quickselect(p + 1, right)
                
        return quickselect(0, len(nums) - 1)