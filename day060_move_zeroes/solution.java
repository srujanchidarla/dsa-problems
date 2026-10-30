class SolutionBruteForce {
    // O(n) time | O(n) space — collect non-zeroes, then pad with zeroes.
    public void moveZeroes(int[] nums) {
        int[] kept = new int[nums.length];
        int k = 0;
        for (int x : nums) if (x != 0) kept[k++] = x;
        for (int i = 0; i < nums.length; i++) nums[i] = kept[i];
    }
}

class Solution {
    // O(n) time | O(1) space — read/write pointers, fill tail with 0.
    public void moveZeroes(int[] nums) {
        int write = 0;
        for (int read = 0; read < nums.length; read++) {
            if (nums[read] != 0) nums[write++] = nums[read];
        }
        for (int i = write; i < nums.length; i++) nums[i] = 0;
    }
}
