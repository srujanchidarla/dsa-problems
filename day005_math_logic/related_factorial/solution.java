import java.util.Scanner;

class Solution {

    // O(N) Time, O(1) Space - Iterative (Optimal)
    public static long calculateFactorial_iterative(int N) {
        if (N < 0) return -1;
        if (N == 0 || N == 1) return 1;

        // Use 'long' to prevent overflow for larger factorials
        long result = 1;
        for (int i = 2; i <= N; i++) {
            result *= i;
        }
        return result;
    }

    // O(N) Time, O(N) Stack Space - Recursive (Brute Force/Alternative)
    public static long calculateFactorial_recursive(int N) {
        if (N < 0) return -1;
        if (N == 0 || N == 1) return 1;
        
        // Recursive call: N * (N-1)!
        return (long)N * calculateFactorial_recursive(N - 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt();
        
        // Use the iterative O(N) approach
        System.out.println(calculateFactorial_iterative(N));
        scanner.close();
    }
}