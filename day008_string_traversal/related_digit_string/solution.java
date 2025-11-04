import java.util.Scanner;

class Solution {

    // Optimal: O(N) Time - Single Pass
    public static void solve_digit_string() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String S = scanner.nextLine();
        
        if (S.isEmpty()) {
            System.out.println("NO");
            return;
        }
        
        if (S.matches("\\d+")) { // Java regex is often cleanest
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        scanner.close();
    }

    // Brute Force: O(N) Time - Manual Character.isDigit() check
    public static void solve_digit_string_brute() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String S = scanner.nextLine();
        
        if (S.isEmpty()) {
            System.out.println("NO");
            return;
        }
        
        for (int i = 0; i < S.length(); i++) {
            if (!Character.isDigit(S.charAt(i))) {
                System.out.println("NO");
                scanner.close();
                return;
            }
        }
        System.out.println("YES");
        scanner.close();
    }

    public static void main(String[] args) {
        solve_digit_string();
    }
}