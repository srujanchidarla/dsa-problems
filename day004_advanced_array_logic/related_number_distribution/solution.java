import java.util.Scanner;
import java.util.Map;
import java.util.TreeMap; 
import java.util.Arrays;

class Solution {

    // Optimized: O(N) Time, O(N) Space - Uses HashMap for frequency count
    public static void solve_number_distribution_optimized(int N, Scanner scanner) {
        // Using TreeMap for sorted output, but HashMap is faster if order doesn't matter (O(N) time)
        Map<Integer, Integer> counts = new TreeMap<>();
        int[] nums = new int[N];

        for (int i = 0; i < N; i++) {
            if (!scanner.hasNextInt()) return;
            int num = scanner.nextInt();
            nums[i] = num;
            
            // Increment the count for the number 'num'
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }
        
        // Print the results (element: frequency)
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
    
    // Brute Force: O(N log N) Time, O(1) or O(N) Space - Sorts the array and iterates
    public static void solve_number_distribution_brute(int N, Scanner scanner) {
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            if (!scanner.hasNextInt()) return;
            nums[i] = scanner.nextInt();
        }

        // Sort the array (O(N log N))
        Arrays.sort(nums);
        
        if (N == 0) return;

        int currentElement = nums[0];
        int count = 0;

        for (int i = 0; i < N; i++) {
            if (nums[i] == currentElement) {
                count++;
            } else {
                System.out.println(currentElement + ": " + count);
                currentElement = nums[i];
                count = 1;
            }
        }
        // Print the last element's count
        System.out.println(currentElement + ": " + count);
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt();
        
        // Since input can only be read once, you'd typically choose one solver.
        // We'll use the optimized version and assume the remaining input stream follows N.
        solve_number_distribution_optimized(N, scanner); 
        
        scanner.close();
    }
}