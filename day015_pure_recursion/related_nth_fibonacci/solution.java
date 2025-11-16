import java.util.Scanner;

class Solution {
    
    // Optimized: O(N) Time, O(N) Space - Memoization
    public int fib_memo(int N, int[] memo) {
        if (N <= 1) {
            return N;
        }
        if (memo[N] != -1) {
            return memo[N];
        }
        
        // Cache the result
        memo[N] = fib_memo(N - 1, memo) + fib_memo(N - 2, memo);
        return memo[N];
    }

    // Brute Force: O(2^N) Time, O(N) Space - Pure Recursion
    public int fib_pure_recursion(int N) {
        if (N <= 1) {
            return N;
        }
        return fib_pure_recursion(N - 1) + fib_pure_recursion(N - 2);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt();
        
        Solution solution = new Solution();
        int[] memo = new int[N + 1];
        java.util.Arrays.fill(memo, -1);
        
        System.out.println("Fib(N): " + solution.fib_memo(N, memo));
        scanner.close();
    }
}