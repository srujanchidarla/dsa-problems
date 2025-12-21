from typing import List

class Solution:
    # Optimized: O(N + K) Time, O(N + K) Space
    def countingSort(self, nums: List[int]) -> List[int]:
        if not nums:
            return nums
        
        # 1. Find the range (handling negative numbers with an offset)
        min_val = min(nums)
        max_val = max(nums)
        range_of_elements = max_val - min_val + 1
        
        # 2. Initialize the count array
        count = [0] * range_of_elements
        output = [0] * len(nums)
        
        # 3. Store the frequency of each element
        for num in nums:
            count[num - min_val] += 1
            
        # 4. Modify count[i] to contain the actual position in output
        for i in range(1, len(count)):
            count[i] += count[i - 1]
            
        # 5. Build the output array (traverse backwards for stability)
        for i in range(len(nums) - 1, -1, -1):
            output[count[nums[i] - min_val] - 1] = nums[i]
            count[nums[i] - min_val] -= 1
            
        return output