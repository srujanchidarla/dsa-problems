import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(n) time | O(1) space
    // Operation preserves source[i] + source[j] → total sum is invariant
    // ─────────────────────────────────────────────────────────────────────
    static boolean canTransform(int[] source, int[] target) {
        long sourceSum = 0;                      // long: up to 10^5 * 10^9
        long targetSum = 0;

        for (int x : source) sourceSum += x;
        for (int x : target) targetSum += x;

        return sourceSum == targetSum;           // same sum ⇔ reachable
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] source = new int[n];
        int[] target = new int[n];

        for (int i = 0; i < n; i++) source[i] = sc.nextInt();
        for (int i = 0; i < n; i++) target[i] = sc.nextInt();

        System.out.println(canTransform(source, target));

        sc.close();
    }
}
