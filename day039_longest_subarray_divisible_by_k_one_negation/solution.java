import java.util.Scanner;

public class solution {

    static int modK(long v, int k) {
        return (int) (((v % k) + k) % k);        // non-negative remainder
    }

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(n²) time | O(k) space
    // Negating x turns S into S - 2x → valid iff S ≡ 0 or S ≡ 2x (mod k)
    // ─────────────────────────────────────────────────────────────────────
    static int longestSubarray(int[] nums, int k) {
        int n = nums.length, best = 0;
        boolean[] seen = new boolean[k];         // remainders of 2x in window

        for (int l = 0; l < n; l++) {
            long sum = 0;

            for (int r = l; r < n; r++) {
                sum += nums[r];                  // extend window
                seen[modK(2L * nums[r], k)] = true;

                int target = modK(sum, k);
                if (target == 0 || seen[target]) {
                    best = Math.max(best, r - l + 1);
                }
            }

            for (int r = l; r < n; r++) {        // reset only touched slots
                seen[modK(2L * nums[r], k)] = false;
            }
        }

        return best;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        System.out.println(longestSubarray(nums, k));

        sc.close();
    }
}
