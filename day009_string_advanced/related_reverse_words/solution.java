import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Solution {

    // Optimized: O(N) Time, O(N) Space - Split, Reverse List, Join
    public static void solve_reverse_words() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String S = scanner.nextLine();

        // 1. Split by one or more spaces (\\s+), handles trimming and multiple spaces.
        // The Java split method is linear O(N).
        String[] wordsArray = S.trim().split("\\s+");
        
        // 2. Convert to list and reverse (O(N))
        List<String> wordsList = new ArrayList<>(List.of(wordsArray));
        Collections.reverse(wordsList);
        
        // 3. Join with a single space (O(N))
        String result = String.join(" ", wordsList);
        
        System.out.println(result);
        scanner.close();
    }

    public static void main(String[] args) {
        solve_reverse_words();
    }
}