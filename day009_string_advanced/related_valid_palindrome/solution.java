import java.util.Scanner;

class Solution {

    // O(N) Time, O(1) Space - Optimal (Two Pointers with in-place filtering)
    public static void solve_valid_palindrome() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String S = scanner.nextLine();
        
        int left = 0;
        int right = S.length() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !Character.isLetterOrDigit(S.charAt(left))) {
                left++;
            }
            
            // Skip non-alphanumeric characters from the right
            while (left < right && !Character.isLetterOrDigit(S.charAt(right))) {
                right--;
            }

            // Compare characters (case-insensitive)
            if (left < right && Character.toLowerCase(S.charAt(left)) != Character.toLowerCase(S.charAt(right))) {
                System.out.println("NO");
                scanner.close();
                return;
            }

            // Move pointers inward
            left++;
            right--;
        }
        
        System.out.println("YES");
        scanner.close();
    }

    // O(N) Time, O(N) Space - Brute Force (Preprocessing)
    public static void solve_valid_palindrome_brute() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String S = scanner.nextLine();

        // 1. Filter and convert (O(N) time and space)
        StringBuilder filtered = new StringBuilder();
        for (char c : S.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                filtered.append(Character.toLowerCase(c));
            }
        }
        
        String filteredString = filtered.toString();
        
        // 2. Check if string equals its reverse (O(N) time)
        String reversedString = filtered.reverse().toString();

        if (filteredString.equals(reversedString)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        scanner.close();
    }

    public static void main(String[] args) {
        solve_valid_palindrome();
    }
}