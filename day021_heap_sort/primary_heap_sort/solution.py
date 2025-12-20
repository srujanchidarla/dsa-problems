from typing import List

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        n = len(nums)

        # 1. Build a Max-Heap (O(N))
        # Start from the last non-leaf node and move up to the root
        for i in range(n // 2 - 1, -1, -1):
            self._heapify(nums, n, i)

        # 2. Extract elements one by one (O(N log N))
        for i in range(n - 1, 0, -1):
            # Swap the root (current max) with the last element
            nums[i], nums[0] = nums[0], nums[i]
            # Call heapify on the reduced heap
            self._heapify(nums, i, 0)
            
        return nums

    def _heapify(self, arr: List[int], n: int, i: int):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2

        # If left child exists and is greater than current largest
        if left < n and arr[left] > arr[largest]:
            largest = left

        # If right child exists and is greater than current largest
        if right < n and arr[right] > arr[largest]:
            largest = right

        # If largest is not root
        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i] # swap
            # Recursively heapify the affected sub-tree
            self._heapify(arr, n, largest)