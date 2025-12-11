from typing import List

class Solution:
    def quickSort_optimal(self, nums: List[int], low: int, high: int):
        if low < high:
            # pi is the partitioning index, nums[pi] is now at right place
            pi = self._partition(nums, low, high)
            
            # Recursively sort elements before and after partition
            self.quickSort_optimal(nums, low, pi - 1)
            self.quickSort_optimal(nums, pi + 1, high)

    def _partition(self, nums: List[int], low: int, high: int) -> int:
        # Lomuto Partition Scheme (chooses the last element as pivot)
        pivot = nums[high]
        i = low - 1 # Index of smaller element
        
        for j in range(low, high):
            # If current element is smaller than or equal to pivot
            if nums[j] <= pivot:
                i += 1
                nums[i], nums[j] = nums[j], nums[i] # Swap nums[i] and nums[j]
        
        # Swap the pivot element with the element at i+1
        nums[i + 1], nums[high] = nums[high], nums[i + 1]
        return i + 1

    # Brute Force: O(N^2) Worst Case - Quick Sort without pivot randomization
    def quickSort_brute(self, nums: List[int], low: int, high: int):
        # The brute force case occurs when the input is already sorted 
        # and we pick the last element as pivot, leading to O(N^2).
        self.quickSort_optimal(nums, low, high)