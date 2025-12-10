import java.util.Arrays;

class Solution {

    private void _merge(int[] arr, int low, int mid, int high) {
        int[] temp = new int[high - low + 1];
        int i = low;
        int j = mid + 1;
        int k = 0;

        // 1. Compare and merge
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        // 2. Copy remaining elements
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= high) {
            temp[k++] = arr[j++];
        }

        // 3. Copy back to original array
        for (k = 0; k < temp.length; k++) {
            arr[low + k] = temp[k];
        }
    }

    private void mergeSortRec(int[] arr, int low, int high) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;
        
        mergeSortRec(arr, low, mid);
        mergeSortRec(arr, mid + 1, high);
        
        _merge(arr, low, mid, high);
    }

    public void mergeSort_optimal(int[] nums) {
        if (nums == null || nums.length <= 1) return;
        mergeSortRec(nums, 0, nums.length - 1);
    }
    
    // Brute Force: Any O(N^2) sort
    public void mergeSort_brute(int[] nums) {
        // Implementation of Bubble Sort or Insertion Sort would go here.
    }
}