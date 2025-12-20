from typing import List

class Solution:
    # Optimized: O(N) Time, O(1) Space - Dutch National Flag Algorithm
    def sortColors_optimal(self, nums: List[int]):
        low = 0    # Pointer for the 0s region
        mid = 0    # Current element pointer (the one being checked)
        high = len(nums) - 1 # Pointer for the 2s region
        
        while mid <= high:
            if nums[mid] == 0:
                # Swap current 0 to the low region
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                # 1 is already in the middle region, just move on
                mid += 1
            else: # nums[mid] == 2
                # Swap current 2 to the high region (do NOT increment mid)
                nums[high], nums[mid] = nums[mid], nums[high]
                high -= 1
        
        # This function modifies nums in-place

    # Brute Force: O(N log N) Time - Any general-purpose sort
    def sortColors_brute(self, nums: List[int]):
        # Using Python's built-in sort (TimSort, O(N log N)) for the brute force comparison
        nums.sort()