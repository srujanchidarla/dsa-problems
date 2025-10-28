import java.util.HashMap;
import java.util.Map;

class Solution {

    // 1. Optimized Approach: Time O(n), Space O(n) - HashMap
    public int[] twoSum_optimized(int[] nums, int target) {
        Map<Integer, Integer> numMap = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            
            if (numMap.containsKey(complement)) {
                return new int[] { numMap.get(complement), i };
            }
            
            numMap.put(nums[i], i);
        }
        
        return new int[0]; // Should not be reached
    }

    // 2. Brute Force Approach: Time O(n^2), Space O(1)
    public int[] twoSum_brute(int[] nums, int target) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[] { i, j };
                }
            }
        }
        return new int[0]; // Should not be reached
    }
    
    // Default entry point (use the optimized one for submissions)
    public int[] twoSum(int[] nums, int target) {
        return twoSum_optimized(nums, target);
    }
}