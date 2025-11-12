import java.util.Scanner;

class Solution {

    // Helper function to count digits (O(log N))
    private static int countDigits(long n) {
        if (n == 0) return 1;
        n = Math.abs(n);
        return String.valueOf(n).length(); // Easiest way in Java, still O(log N)
    }

    // O(log N) Time, O(1) Space - Optimal
    public static boolean isPalindrome_optimal(long n) {
        if (n < 0) return false;
        long original = n;
        long reversed = 0;
        long temp = n;
        while (temp > 0) {
            reversed = reversed * 10 + (temp % 10);
            temp /= 10;
        }
        return original == reversed;
    }

    // O(log N) Time, O(1) Space - Optimal
    public static boolean isArmstrong_optimal(long n) {
        if (n < 0) return false;
        int D = countDigits(n);
        long original = n;
        long sum = 0;
        long temp = n;
        
        while (temp > 0) {
            int lastDigit = (int)(temp % 10);
            sum += Math.pow(lastDigit, D);
            temp /= 10;
        }
        return original == sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLong()) return;
        long N = scanner.nextLong();
        
        System.out.println("Palindrome: " + (isPalindrome_optimal(N) ? "YES" : "NO"));
        System.out.println("Armstrong: " + (isArmstrong_optimal(N) ? "YES" : "NO"));
        scanner.close();
    }
}