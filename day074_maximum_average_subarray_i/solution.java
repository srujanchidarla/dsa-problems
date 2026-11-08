class SolutionBruteForce {
    // O(n * k) time | O(1) space — recompute every window's sum.
    public double findMaxAverage(int[] nums, int k) {
        double best = Double.NEGATIVE_INFINITY;
        for (int i = 0; i <= nums.length - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) sum += nums[j];
            best = Math.max(best, (double) sum / k);
        }
        return best;
    }
}

class Solution {
    // O(n) time | O(1) space — sliding window sum, divide once at the end.
    public double findMaxAverage(int[] nums, int k) {
        int window = 0;
        for (int i = 0; i < k; i++) window += nums[i];
        int best = window;
        for (int i = k; i < nums.length; i++) {
            window += nums[i] - nums[i - k];
            best = Math.max(best, window);
        }
        return (double) best / k;
    }
}
