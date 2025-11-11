import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

class Solution {

    // O(N^2) Time, O(1) Space - Optimal: Boundary Pointers
    public static void spiralTraversal_optimal(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return;
        int R = matrix.length;
        int C = matrix[0].length;
        
        int top = 0, bottom = R - 1;
        int left = 0, right = C - 1;

        while (top <= bottom && left <= right) {
            // 1. Traverse Right (Top row)
            for (int j = left; j <= right; j++) {
                System.out.print(matrix[top][j] + " ");
            }
            top++;

            // 2. Traverse Down (Right column)
            for (int i = top; i <= bottom; i++) {
                System.out.print(matrix[i][right] + " ");
            }
            right--;

            // 3. Traverse Left (Bottom row)
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    System.out.print(matrix[bottom][j] + " ");
                }
                bottom--;
            }

            // 4. Traverse Up (Left column)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    System.out.print(matrix[i][left] + " ");
                }
                left++;
            }
        }
        System.out.println();
    }
}