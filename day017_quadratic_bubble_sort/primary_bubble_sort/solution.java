class Solution {
    // Optimized: O(N^2) Time (Worst/Avg), O(N) Time (Best), O(1) Space
    public void bubbleSort_optimized(int[] nums) {
        int N = nums.length;
        for (int i = 0; i < N - 1; i++) {
            boolean swapped = false;
            // Inner loop runs up to N-i-1
            for (int j = 0; j < N - 1 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    // Swap
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    swapped = true;
                }
            }
            // Optimization check
            if (!swapped) {
                break;
            }
        }
    }

    // Brute Force: O(N^2) Time (Always) - No early exit
    public void bubbleSort_brute(int[] nums) {
        int N = nums.length;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    // Swap
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
}