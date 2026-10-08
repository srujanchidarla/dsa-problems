import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(n) time | O(1) space
    // Only one bracket type → a counter replaces the stack
    // ─────────────────────────────────────────────────────────────────────
    static int maxDepth(String s) {
        int depth = 0;                           // current nesting level
        int best  = 0;                           // deepest level seen

        for (char c : s.toCharArray()) {
            if (c == '(') {
                depth++;                         // go deeper
                best = Math.max(best, depth);
            } else if (c == ')') {
                depth--;                         // come back up
            }
        }

        return best;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        System.out.println(maxDepth(s));

        sc.close();
    }
}
