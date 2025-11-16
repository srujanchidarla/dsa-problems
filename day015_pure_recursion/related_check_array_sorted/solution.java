import java.util.Scanner;

class Solution {
    
    // Optimized: O(N) Time, O(N) Space - Recursive Subdivision
    public static boolean is_sorted_recursive(int[] arr, int index) {
        // Base Case 1: Reached the end
        if (index == arr.length - 1) {
            return true;
        }
        
        // Base Case 2 (Failure): Current pair is out of order
        if (arr[index] > arr[index + 1]) {
            return false;
        }
        
        // Recursive Step
        return is_sorted_recursive(arr, index + 1);
    }

    // Brute Force: O(N) Time, O(1) Space - Iterative
    public static boolean is_sorted_iterative(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
}