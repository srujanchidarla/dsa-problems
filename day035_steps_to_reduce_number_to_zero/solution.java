import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // BRUTE FORCE — O(log n) time | O(1) space
    // Simulate: even → divide by 2, odd → subtract 1
    // ─────────────────────────────────────────────────────────────────────
    static int numberOfStepsBruteForce(int num) {
        int steps = 0;

        while (num > 0) {
            if (num % 2 == 0) num /= 2;          // even → halve
            else              num -= 1;          // odd  → drop the last 1-bit
            steps++;
        }

        return steps;
    }

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(1) time | O(1) space
    // popcount + (bit length - 1)
    // ─────────────────────────────────────────────────────────────────────
    static int numberOfSteps(int num) {
        if (num == 0) return 0;

        int ones      = Integer.bitCount(num);                  // subtract steps
        int bitLength = 32 - Integer.numberOfLeadingZeros(num); // total bits

        return ones + bitLength - 1;                            // + divide steps
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();
        System.out.println(numberOfSteps(num));

        sc.close();
    }
}
