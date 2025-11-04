import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class Solution {

    // O(N) Time, O(1) Space - Optimal (Set Lookup)
    public static void solve_vowels_consonants() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String S = scanner.nextLine().toLowerCase();
        
        // Use HashSet for O(1) lookup
        Set<Character> VOWELS = new HashSet<>(Set.of('a', 'e', 'i', 'o', 'u'));
        int vowelCount = 0;
        int consonantCount = 0;

        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            
            if (c >= 'a' && c <= 'z') {
                if (VOWELS.contains(c)) {
                    vowelCount++;
                } else {
                    consonantCount++;
                }
            }
        }
        
        System.out.println("Vowels: " + vowelCount);
        System.out.println("Consonants: " + consonantCount);
        scanner.close();
    }

    public static void main(String[] args) {
        solve_vowels_consonants();
    }
}