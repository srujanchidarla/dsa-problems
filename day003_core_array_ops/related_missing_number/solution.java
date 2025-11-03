import java.util.Scanner;

class Solution {

    // Optimized: O(N) Time, O(1) Space - Summation Method
    public static long findMissingNumber_summation(int[] nums) {
        int N = nums.length;
        
        // N is the length of the array, range is 0 to N.
        // Calculate Expected Sum: N * (N + 1) / 2
        long expectedSum = (long)N * (N + 1) / 2;

        // Calculate Actual Sum (O(N))
        long actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }

    // Alternative Optimal: O(N) Time, O(1) Space - XOR Method
    public static int findMissingNumber_xor(int[] nums) {
        int N = nums.length;
        int missing = N; // Initialize with N

        // XOR all indices (0 to N-1) and all array elements
        for (int i = 0; i < N; i++) {
            missing ^= i;
            missing ^= nums[i];
        }
        
        return missing;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read N (array size)
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt();
        
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            if (!scanner.hasNextInt()) return;
            nums[i] = scanner.nextInt();
        }

        long missingNumber = findMissingNumber_summation(nums);
        System.out.println(missingNumber);
        
        scanner.close();
    }
}