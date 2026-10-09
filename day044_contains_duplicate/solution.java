import java.util.HashSet;
import java.util.Set;

class SolutionBruteForce {
    // O(n^2) time | O(1) space — for each element, scan the rest.
    public boolean containsDuplicate(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
}

class Solution {
    // O(n) time | O(n) space — one pass with a set, early exit.
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (seen.contains(num)) return true;
            seen.add(num);
        }
        return false;
    }
}
