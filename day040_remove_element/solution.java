import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(n) time | O(1) space
    // Two pointers: copy every non-val element to the write position
    // ─────────────────────────────────────────────────────────────────────
    static int removeElement(int[] nums, int val) {
        int write = 0;                           // next slot for a kept value

        for (int read = 0; read < nums.length; read++) {
            if (nums[read] != val) {             // keep it
                nums[write] = nums[read];
                write++;
            }
        }

        return write;                            // count of kept elements
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int val = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int k = removeElement(nums, val);

        StringBuilder sb = new StringBuilder();
        sb.append(k).append("\n");
        for (int i = 0; i < k; i++) {
            sb.append(nums[i]).append(i + 1 < k ? " " : "");
        }
        System.out.println(sb);

        sc.close();
    }
}
