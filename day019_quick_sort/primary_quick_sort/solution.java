class Solution {
    private int _partition(int[] nums, int low, int high) {
        // Lomuto Partition Scheme
        int pivot = nums[high];
        int i = low - 1; 

        for (int j = low; j < high; j++) {
            if (nums[j] <= pivot) {
                i++;
                // Swap nums[i] and nums[j]
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        // Swap pivot into its correct place
        int temp = nums[i + 1];
        nums[i + 1] = nums[high];
        nums[high] = temp;
        
        return i + 1;
    }

    private void quickSortRec(int[] nums, int low, int high) {
        if (low < high) {
            int pi = _partition(nums, low, high);
            quickSortRec(nums, low, pi - 1);
            quickSortRec(nums, pi + 1, high);
        }
    }

    public void quickSort_optimal(int[] nums) {
        if (nums == null || nums.length <= 1) return;
        quickSortRec(nums, 0, nums.length - 1);
    }
    
    public void quickSort_brute(int[] nums) {
        quickSort_optimal(nums);
    }
}