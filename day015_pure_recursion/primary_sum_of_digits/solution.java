import java.util.Scanner;

class Solution {
    // Optimized: O(log N) Time, O(log N) Space - Recursive
    public static int sum_digits_recursive(int N) {
        N = Math.abs(N);
        if (N == 0) {
            return 0;
        }
        return (N % 10) + sum_digits_recursive(N / 10);
    }

    // Brute Force: O(log N) Time, O(1) Space - Iterative
    public static int sum_digits_iterative(int N) {
        N = Math.abs(N);
        int sumVal = 0;
        while (N > 0) {
            sumVal += N % 10;
            N /= 10;
        }
        return sumVal;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt();
        System.out.println(sum_digits_recursive(N));
        scanner.close();
    }
}