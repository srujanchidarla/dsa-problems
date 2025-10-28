import java.util.HashSet;
import java.util.Set;

class Solution {

    // 1. Brute Force Approach: Time O(n^2), Space O(1)
    // Compares every pair of elements.
    public boolean containsDuplicate_brute(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    // 2. Optimized Approach: Time O(n), Space O(n) - HashSet
    // Uses a set for O(1) average time complexity lookups.
    public boolean containsDuplicate_optimized(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            // If add() returns false, the element was already in the set (duplicate)
            if (!seen.add(num)) {
                return true; 
            }
        }
        return false;
    }
    
    // Default entry point (using the optimized method)
    public boolean containsDuplicate(int[] nums) {
        return containsDuplicate_optimized(nums);
    }
}