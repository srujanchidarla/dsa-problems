class Solution {
    // Optimized: O(N) Time, O(1) Space - Dutch National Flag Algorithm
    public void sortColors_optimal(int[] nums) {
        int low = 0;
        int mid = 0;
        int high = nums.length - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap nums[low] and nums[mid]
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                // Swap nums[high] and nums[mid]
                int temp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = temp;
                high--;
                // Note: mid is NOT incremented here
            }
        }
    }
    
    // Brute Force: O(N log N) Time - Using standard library sort
    public void sortColors_brute(int[] nums) {
        java.util.Arrays.sort(nums);
    }
}