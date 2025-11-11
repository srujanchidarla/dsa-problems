
class Solution {

    // Optimized: O(N) Time, O(1) Space - Backward Greedy Traversal
    public boolean canJump_optimal(int[] nums) {
        if (nums == null || nums.length == 0) return false;
        
        int goal = nums.length - 1;

        // Iterate backward
        for (int i = nums.length - 2; i >= 0; i--) {
            // Check if current position can reach or pass the goal
            if (i + nums[i] >= goal) {
                goal = i; // Update goal
            }
        }
        
        return goal == 0;
    }

    // Brute Force: O(N^2) Time - Dynamic Programming
    public boolean canJump_brute(int[] nums) {
        int N = nums.length;
        if (N <= 1) return true;
        
        boolean[] memo = new boolean[N];
        memo[N - 1] = true;

        for (int i = N - 2; i >= 0; i--) {
            int maxJump = Math.min(i + nums[i], N - 1);
            for (int j = i + 1; j <= maxJump; j++) {
                if (memo[j]) {
                    memo[i] = true;
                    break;
                }
            }
        }
        return memo[0];
    }
}