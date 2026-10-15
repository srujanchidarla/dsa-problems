import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // BRUTE FORCE — O(n²) time | O(1) auxiliary space
    // For each kid, compare against every other kid
    // ─────────────────────────────────────────────────────────────────────
    static List<Boolean> kidsWithCandiesBruteForce(int[] candies, int extraCandies) {
        List<Boolean> result = new ArrayList<>(candies.length);
        for (int c : candies) {
            boolean ok = true;
            for (int other : candies) {
                if (c + extraCandies < other) {  // someone still has more → not greatest
                    ok = false;
                    break;
                }
            }
            result.add(ok);
        }
        return result;
    }

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(n) time | O(1) auxiliary space
    // Find the max once, then one comparison per kid
    // ─────────────────────────────────────────────────────────────────────
    static List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int mx = 0;
        for (int c : candies) mx = Math.max(mx, c);  // current greatest

        List<Boolean> result = new ArrayList<>(candies.length);
        for (int c : candies) {
            result.add(c + extraCandies >= mx);      // ties count as greatest
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int extraCandies = sc.nextInt();
        int[] candies = new int[n];
        for (int i = 0; i < n; i++) {
            candies[i] = sc.nextInt();
        }

        System.out.println(kidsWithCandies(candies, extraCandies));

        sc.close();
    }
}
