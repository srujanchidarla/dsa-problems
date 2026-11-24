import java.util.Arrays;

class SolutionBruteForce {
    // O(n log n) time | O(1) space — sort, then scan for the first gap.
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int want = 1;
        for (int v : nums) {
            if (v == want) want++;
            else if (v > want) break;
        }
        return want;
    }
}

class Solution {
    // O(n) time | O(1) space — cyclic sort: value v belongs at index v - 1.
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        int i = 0;
        while (i < n) {
            int v = nums[i];
            if (v >= 1 && v <= n && nums[v - 1] != v) {
                int tmp = nums[i];
                nums[i] = nums[v - 1];
                nums[v - 1] = tmp;
            } else {
                i++;
            }
        }
        for (int j = 0; j < n; j++) {
            if (nums[j] != j + 1) return j + 1;
        }
        return n + 1;
    }
}
