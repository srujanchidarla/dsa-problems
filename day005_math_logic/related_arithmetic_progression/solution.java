import java.util.Scanner;

class Solution {

    // O(N) Time, O(1) Space - Optimal/Brute
    public static boolean isArithmeticProgression(int[] nums) {
        int N = nums.length;
        
        if (N <= 2) return true; 

        // Calculate the common difference (O(1))
        int diff = nums[1] - nums[0];

        // Check every consecutive difference (O(N))
        for (int i = 2; i < N; i++) {
            if (nums[i] - nums[i-1] != diff) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt();
        
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            if (!scanner.hasNextInt()) return;
            nums[i] = scanner.nextInt();
        }

        if (isArithmeticProgression(nums)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        scanner.close();
    }
}