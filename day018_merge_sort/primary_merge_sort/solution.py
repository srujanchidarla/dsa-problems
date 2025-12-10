from typing import List

class Solution:
    def mergeSort(self, nums: List[int]):
        if len(nums) <= 1:
            return nums
        
        mid = len(nums) // 2
        left = self.mergeSort(nums[:mid]) # Divide
        right = self.mergeSort(nums[mid:]) # Divide
        
        return self._merge(left, right) # Conquer

    def _merge(self, left, right):
        result = []
        i = j = 0
        
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                j += 1
                
        # Append remaining elements
        result.extend(left[i:])
        result.extend(right[j:])
        return result