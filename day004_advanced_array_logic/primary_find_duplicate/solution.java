import java.util.Scanner;

class Solution {

    // Optimized: O(N) Time, O(1) Space - Floyd's Tortoise and Hare (Cycle Detection)
    public static int findDuplicate_optimal(int[] nums) {
        if (nums == null || nums.length == 0) return -1;

        // Phase 1: Detect the intersection point
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // Phase 2: Find the entry point (the duplicate number)
        // Reset slow to the start (index 0)
        slow = nums[0];
        // fast remains at the intersection point
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    // Brute Force: O(N^2) Time, O(1) Space - Nested loops
    public static int findDuplicate_brute(int[] nums) {
        int N = nums.length;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        return -1; // Should not happen based on problem constraints
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read N (number of elements, which is array size)
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt(); 
        
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            if (!scanner.hasNextInt()) return;
            nums[i] = scanner.nextInt();
        }

        // Use the optimized O(N) approach
        int duplicate = findDuplicate_optimal(nums);
        System.out.println(duplicate);
        
        scanner.close();
    }
}