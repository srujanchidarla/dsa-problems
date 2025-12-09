from typing import List

class Solution:
    # Optimized: O(N^2) Time (Worst/Avg), O(N) Time (Best), O(1) Space
    def bubbleSort_optimized(self, nums: List[int]):
        N = len(nums)
        for i in range(N):
            swapped = False
            # The inner loop iterates up to N-i-1 because the last i elements are already in place
            for j in range(N - 1 - i):
                if nums[j] > nums[j + 1]:
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
                    swapped = True
            
            # Optimization: If no two elements were swapped in inner loop, then array is sorted
            if not swapped:
                break
        return nums

    # Brute Force: O(N^2) Time (Always) - No early exit optimization
    def bubbleSort_brute(self, nums: List[int]):
        N = len(nums)
        for i in range(N):
            # Outer loop always runs N times
            for j in range(N - 1):
                if nums[j] > nums[j + 1]:
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
        return nums