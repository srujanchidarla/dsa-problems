import java.util.Arrays;

class Solution {
    // O(N + K) Time, O(N + K) Space
    public int[] countingSort(int[] nums) {
        if (nums == null || nums.length == 0) return nums;

        int minVal = nums[0];
        int maxVal = nums[0];
        for (int num : nums) {
            if (num < minVal) minVal = num;
            if (num > maxVal) maxVal = num;
        }

        int range = maxVal - minVal + 1;
        int[] count = new int[range];
        int[] output = new int[nums.length];

        // Frequency Count
        for (int num : nums) {
            count[num - minVal]++;
        }

        // Cumulative Count for Stability
        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

        // Output Construction
        for (int i = nums.length - 1; i >= 0; i--) {
            output[count[nums[i] - minVal] - 1] = nums[i];
            count[nums[i] - minVal]--;
        }

        return output;
    }
}