import java.util.Scanner;
import java.util.Collections;
import java.util.Arrays;

class Solution {

    // O(N^2) Time, O(1) Space - Optimal: Transpose then Reverse
    public static void rotateMatrix_optimal(int[][] matrix) {
        int N = matrix.length;

        // 1. Transpose: Swap matrix[i][j] with matrix[j][i]
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // 2. Reverse each row
        for (int i = 0; i < N; i++) {
            // Use a two-pointer approach for in-place reversal
            int left = 0;
            int right = N - 1;
            while (left < right) {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                left++;
                right--;
            }
        }
    }

    // O(N^2) Time, O(N^2) Space - Brute Force (Extra Space)
    public static int[][] rotateMatrix_brute(int[][] matrix) {
        int N = matrix.length;
        int[][] rotated = new int[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // Rotation rule: rotated[j][N - 1 - i] = matrix[i][j]
                rotated[j][N - 1 - i] = matrix[i][j];
            }
        }
        return rotated;
    }
}