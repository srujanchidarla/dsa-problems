import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(n) time | O(1) space
    // Single pass — bucket each number into positive, negative, or zero
    // ─────────────────────────────────────────────────────────────────────
    static int[] distribute(int[] arr) {
        int pos  = 0;                            // count of positive numbers
        int neg  = 0;                            // count of negative numbers
        int zero = 0;                            // count of zeros

        for (int num : arr) {
            if (num > 0)      pos++;             // positive bucket
            else if (num < 0) neg++;             // negative bucket
            else              zero++;            // zero bucket
        }

        return new int[]{pos, neg, zero};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();                    // read count of numbers
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();               // read each number
        }

        int[] result = distribute(arr);
        System.out.println(result[0]);           // positives
        System.out.println(result[1]);           // negatives
        System.out.println(result[2]);           // zeros

        sc.close();
    }
}