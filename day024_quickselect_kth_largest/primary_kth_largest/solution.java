import java.util.Random;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        int left = 0, right = nums.length - 1;
        int target = k - 1;
        Random rand = new Random();

        while (left <= right) {
            int pivotIndex = left + rand.nextInt(right - left + 1);
            int p = partition(nums, left, right, pivotIndex);
            
            if (p == target) {
                return nums[p];
            } else if (p > target) {
                right = p - 1;
            } else {
                left = p + 1;
            }
        }
        return -1;
    }

    private int partition(int[] nums, int left, int right, int pivotIndex) {
        int pivot = nums[pivotIndex];
        swap(nums, pivotIndex, right);
        int p = left;
        
        for (int i = left; i < right; i++) {
            if (nums[i] >= pivot) {
                swap(nums, i, p);
                p++;
            }
        }
        swap(nums, p, right);
        return p;
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}