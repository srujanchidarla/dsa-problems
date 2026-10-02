import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(n) time | O(1) space
    // Two pointers: read scans, write marks the next unique slot
    // ─────────────────────────────────────────────────────────────────────
    static int removeDuplicates(int[] nums) {
        int write = 1;                           // nums[0] is always unique

        for (int read = 1; read < nums.length; read++) {
            if (nums[read] != nums[write - 1]) { // new value found
                nums[write] = nums[read];        // place it at write
                write++;
            }
        }

        return write;                            // count of unique elements
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int k = removeDuplicates(nums);

        StringBuilder sb = new StringBuilder();
        sb.append(k).append("\n");
        for (int i = 0; i < k; i++) {
            sb.append(nums[i]).append(i + 1 < k ? " " : "");
        }
        System.out.println(sb);

        sc.close();
    }
}
