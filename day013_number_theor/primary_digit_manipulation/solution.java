import java.util.Scanner;

class Solution {

    // O(log N) Time, O(1) Space
    public static void solve_digit_manipulation() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLong()) return;
        long N = scanner.nextLong();
        
        long originalN = N;
        long num = Math.abs(N);

        // --- 1. Count Digits ---
        long tempCount = num;
        int count = 0;
        
        if (num == 0) {
            count = 1;
        } else {
            while (tempCount > 0) {
                tempCount /= 10;
                count++;
            }
        }
        System.out.println("Count: " + count);

        // --- 2. Reverse Number ---
        long tempReverse = num;
        long reversedNum = 0;
        
        while (tempReverse > 0) {
            int lastDigit = (int)(tempReverse % 10);
            reversedNum = reversedNum * 10 + lastDigit;
            tempReverse /= 10;
        }
        
        if (originalN < 0) {
            reversedNum *= -1;
        }
        
        System.out.println("Reversed: " + reversedNum);
        scanner.close();
    }

    public static void main(String[] args) {
        solve_digit_manipulation();
    }
}