import java.util.Scanner;

class Solution {

    // O(N) Time, O(1) Space - Greedy Local Minimization
    public static void solve_ternary_array_cost() {
        Scanner scanner = new Scanner(System.in);
        
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt();

        long minTotalCost = 0;
        
        for (int i = 0; i < N; i++) {
            if (!scanner.hasNextInt()) break;
            int A_i = scanner.nextInt();

            int[] TERNARY = {0, 1, 2};
            long minLocalCost = Long.MAX_VALUE;

            for (int B_i : TERNARY) {
                // Constraint check: A[i] != B[i]
                if (A_i != B_i) {
                    // Calculate cost: |A[i] - B[i]|
                    long cost = Math.abs((long)A_i - B_i);
                    
                    // Update the minimum local cost
                    minLocalCost = Math.min(minLocalCost, cost);
                }
            }
            
            // Add the minimum local cost to the total
            if (minLocalCost != Long.MAX_VALUE) {
                minTotalCost += minLocalCost;
            }
        }

        System.out.println(minTotalCost);
        scanner.close();
    }

    public static void main(String[] args) {
        solve_ternary_array_cost();
    }
}