import sys
from typing import List

class Solution:
    # Optimized: O(N) Time, O(N) Space - Recursive Subdivision
    def is_sorted_recursive(self, arr: List[int], index: int) -> bool:
        # Base Case 1: Reached the end (empty or single-element array remaining)
        if index == len(arr) - 1:
            return True
        
        # Recursive Step: Check current pair AND if the rest of the array is sorted
        if arr[index] > arr[index + 1]:
            return False
        
        return self.is_sorted_recursive(arr, index + 1)

    # Brute Force: O(N) Time, O(1) Space - Iterative
    def is_sorted_iterative(self, arr: List[int]) -> bool:
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                return False
        return True