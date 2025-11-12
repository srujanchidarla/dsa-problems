import sys
from typing import List

class Solution:
    # Optimized: O(N * N!) Time, O(N * N!) Space - Backtracking with State Tracking (Visited Array)
    def permutations_optimal(self, nums: List[int]) -> List[List[int]]:
        results = []
        N = len(nums)
        # Use a boolean array to track which elements are used (O(N) space)
        visited = [False] * N 

        def backtrack(current_permutation):
            # Base Case: Permutation is complete
            if len(current_permutation) == N:
                results.append(list(current_permutation))
                return
            
            for i in range(N):
                if not visited[i]:
                    # 1. Choose: Mark as visited and add to current
                    visited[i] = True
                    current_permutation.append(nums[i])
                    
                    # 2. Recurse
                    backtrack(current_permutation)
                    
                    # 3. Backtrack: Reset state
                    current_permutation.pop()
                    visited[i] = False
        
        backtrack([])
        return results
    
    # Brute Force: O(N * N!) - The problem is inherently factorial, so the complexity is fixed.
    def permutations_brute(self, nums: List[int]) -> List[List[int]]:
        return self.permutations_optimal(nums)