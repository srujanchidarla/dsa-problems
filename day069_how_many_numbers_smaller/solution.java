class SolutionBruteForce {
    // O(n^2) time | O(1) extra space — compare every pair.
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] answer = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] < nums[i]) count++;
            }
            answer[i] = count;
        }
        return answer;
    }
}

class Solution {
    // O(n) time | O(101) space — count values, then prefix sums.
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] count = new int[101];
        for (int v : nums) count[v]++;
        int[] smaller = new int[101];
        int running = 0;
        for (int v = 0; v <= 100; v++) {
            smaller[v] = running;
            running += count[v];
        }
        int[] answer = new int[nums.length];
        for (int i = 0; i < nums.length; i++) answer[i] = smaller[nums[i]];
        return answer;
    }
}
