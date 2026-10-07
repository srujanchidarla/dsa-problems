import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(m + n) time | O(m + n) space (output)
    // One index up to the longer length; append whichever chars still exist
    // ─────────────────────────────────────────────────────────────────────
    static String mergeAlternately(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        StringBuilder sb = new StringBuilder(m + n);

        for (int i = 0; i < Math.max(m, n); i++) {
            if (i < m) sb.append(word1.charAt(i)); // from word1 first
            if (i < n) sb.append(word2.charAt(i)); // then word2
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String word1 = sc.next();
        String word2 = sc.next();

        System.out.println(mergeAlternately(word1, word2));

        sc.close();
    }
}
