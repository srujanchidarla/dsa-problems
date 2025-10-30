import java.util.ArrayList;
import java.util.Scanner;

class Solution {

    public static void solve() {
        // Using Scanner for simple input handling
        Scanner scanner = new Scanner(System.in);
        
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt();
        
        if (!scanner.hasNextInt()) return;
        int M = scanner.nextInt();

        // O(M) Space: Initialize array to store column sums
        long[] colSums = new long[M];
        
        // ArrayList to store row sums for the first required output format (Row Sums)
        ArrayList<Long> rowSumsOutput = new ArrayList<>();

        // --- Combined Input Pass (O(N*M)) ---
        for (int i = 0; i < N; i++) {
            long rowSum = 0; 
            
            for (int j = 0; j < M; j++) {
                if (!scanner.hasNextInt()) return;
                int element = scanner.nextInt(); // Read the element

                // 1. Row Sum Calculation (Streaming)
                rowSum += element;

                // 2. Column Sum Calculation (Storage)
                colSums[j] += element;
            }
            
            // Store Row Sum
            rowSumsOutput.add(rowSum);
        }

        // --- Print Row Sums (Output for Problem 1: Matrix Row Sum) ---
        for (long sum : rowSumsOutput) {
            System.out.println(sum);
        }

        // --- Print Column Sums (Output for Problem 2: Matrix Column Sum) ---
        // Note: Added separator for combined testing; remove for individual problem submission.
        System.out.println("--- Column Sums ---"); 
        for (long sum : colSums) {
            System.out.println(sum);
        }

        scanner.close();
    }
    
    public static void main(String[] args) {
        solve();
    }
}