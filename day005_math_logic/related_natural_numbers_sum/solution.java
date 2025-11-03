import java.util.Scanner;

class Solution {

    // O(1) Time, O(1) Space - Optimal
    public static long sumNaturalNumbers_optimal(long N) {
        // Use the Arithmetic Series Formula: N * (N + 1) / 2
        return N * (N + 1) / 2;
    }

    // O(N) Time, O(1) Space - Brute Force
    public static long sumNaturalNumbers_brute(long N) {
        long sum = 0;
        for (long i = 1; i <= N; i++) {
            sum += i;
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLong()) return;
        long N = scanner.nextLong();
        
        // Use optimal O(1) approach
        System.out.println(sumNaturalNumbers_optimal(N));
        scanner.close();
    }
}