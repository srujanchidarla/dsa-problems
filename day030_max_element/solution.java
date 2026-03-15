import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // BRUTE FORCE — O(n²) time | O(1) space
    // For each element, check if any other element is bigger
    // ─────────────────────────────────────────────────────────────────────
    static int findMaxBrute(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            boolean isMax = true;
            for (int j = 0; j < n; j++) {       // compare arr[i] with everyone
                if (arr[j] > arr[i]) {
                    isMax = false;               // found something bigger
                    break;
                }
            }
            if (isMax) return arr[i];            // nothing was bigger → it's the max
        }
        return arr[0];
    }

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(n) time | O(1) space
    // Single pass, track maximum as we go
    // ─────────────────────────────────────────────────────────────────────
    static int findMax(int[] arr) {
        int maxVal = arr[0];                     // initialize to first element, NOT 0
                                                 // (array could be all negative!)
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > maxVal) {               // found a new maximum
                maxVal = arr[i];                 // update our best
            }
        }
        return maxVal;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();                    // read array size
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();               // read each element
        }

        System.out.println(findMax(arr));        // print the maximum
        sc.close();
    }
}