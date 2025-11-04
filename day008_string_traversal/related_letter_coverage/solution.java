import java.util.Scanner;
import java.util.Arrays;

class Solution {

    // Optimized: O(N) Time, O(1) Space - Boolean Array Hashing
    public static void solve_letter_coverage() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String S = scanner.nextLine().toLowerCase();
        
        // Fixed size array for a-z (O(1) space)
        boolean[] seen = new boolean[26];
        int uniqueCount = 0;

        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            
            if (c >= 'a' && c <= 'z') {
                int index = c - 'a';
                
                if (!seen[index]) {
                    seen[index] = true;
                    uniqueCount++;
                }
            }
        }
        
        if (uniqueCount == 26) {
            System.out.println("Pangram: YES");
        } else {
            System.out.println("Pangram: NO");
        }
        scanner.close();
    }

    public static void main(String[] args) {
        solve_letter_coverage();
    }
}