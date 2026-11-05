import java.util.*;

class SolutionBruteForce {
    // O(n^2) time | O(1) extra space — check every value 1..n by scanning.
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> answer = new ArrayList<>();
        for (int x = 1; x <= nums.length; x++) {
            boolean found = false;
            for (int v : nums) if (v == x) { found = true; break; }
            if (!found) answer.add(x);
        }
        return answer;
    }
}

class Solution {
    // O(n) time | O(1) extra space — mark seen values by flipping signs.
    public List<Integer> findDisappearedNumbers(int[] nums) {
        for (int v : nums) {
            int i = Math.abs(v) - 1;
            if (nums[i] > 0) nums[i] = -nums[i];   // value (i + 1) is present
        }
        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) answer.add(i + 1);
        }
        return answer;
    }
}
