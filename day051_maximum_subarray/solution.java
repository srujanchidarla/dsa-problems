class SolutionBruteForce {
    // O(n^2) time | O(1) space — try every subarray.
    public int maxSubArray(int[] nums) {
        int best = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int s = 0;
            for (int j = i; j < nums.length; j++) {
                s += nums[j];
                best = Math.max(best, s);
            }
        }
        return best;
    }
}

class Solution {
    // O(n) time | O(1) space — Kadane's: restart or extend.
    public int maxSubArray(int[] nums) {
        int cur = nums[0], best = nums[0];
        for (int i = 1; i < nums.length; i++) {
            cur = Math.max(nums[i], cur + nums[i]);
            best = Math.max(best, cur);
        }
        return best;
    }
}
