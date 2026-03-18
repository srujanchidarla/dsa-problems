import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(n) time | O(1) space
    // Single pass — add each number to odd or even accumulator
    // ─────────────────────────────────────────────────────────────────────
    static long[] oddEvenSum(int[] arr) {
        long oddSum  = 0;                        // sum of all odd numbers
        long evenSum = 0;                        // sum of all even numbers

        for (int num : arr) {
            if (Math.abs(num % 2) == 1) {        // Math.abs handles negative numbers
                oddSum  += num;                  // odd bucket
            } else {
                evenSum += num;                  // even bucket
            }
        }

        return new long[]{oddSum, evenSum};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();                    // read array size
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();               // read each element
        }

        long[] result = oddEvenSum(arr);
        System.out.println(result[0]);           // odd sum
        System.out.println(result[1]);           // even sum

        sc.close();
    }
}