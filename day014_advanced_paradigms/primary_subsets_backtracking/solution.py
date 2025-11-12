import sys
from typing import List

class Solution:
    # Optimized: O(N * 2^N) Time, O(N * 2^N) Space - Backtracking/DFS
    def subsets_optimal(self, nums: List[int]) -> List[List[int]]:
        results = []
        
        def backtrack(index, current_subset):
            # Base Case: All elements checked, save the subset
            results.append(list(current_subset))
            
            for i in range(index, len(nums)):
                # 1. Choose (Include nums[i])
                current_subset.append(nums[i])
                
                # 2. Recurse
                backtrack(i + 1, current_subset)
                
                # 3. Backtrack (Exclude nums[i] for the next iteration at this depth)
                current_subset.pop()

        backtrack(0, [])
        return results

    # Alternative Optimal: O(N * 2^N) Time, O(N * 2^N) Space - Bit Manipulation
    def subsets_bit_manipulation(self, nums: List[int]) -> List[List[int]]:
        results = []
        N = len(nums)
        # Iterate through all 2^N masks
        for i in range(1 << N):
            subset = []
            for j in range(N):
                # Check if the j-th bit is set in the mask i
                if (i >> j) & 1:
                    subset.append(nums[j])
            results.append(subset)
        return results