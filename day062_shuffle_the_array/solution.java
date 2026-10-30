class SolutionBruteForce {
    // O(n) time | O(n) space — split into x-half and y-half, then zip them.
    public int[] shuffle(int[] nums, int n) {
        int[] ans = new int[2 * n];
        int[] xs = new int[n];
        int[] ys = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = nums[i];
            ys[i] = nums[i + n];
        }
        for (int i = 0; i < n; i++) {
            ans[2 * i] = xs[i];
            ans[2 * i + 1] = ys[i];
        }
        return ans;
    }
}

class Solution {
    // O(n) time | O(n) space — one pass writes each element to its final slot.
    public int[] shuffle(int[] nums, int n) {
        int[] ans = new int[2 * n];
        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];        // x_i
            ans[2 * i + 1] = nums[i + n];  // y_i
        }
        return ans;
    }
}
