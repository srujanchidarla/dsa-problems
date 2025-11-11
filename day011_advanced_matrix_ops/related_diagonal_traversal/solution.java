import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

class Solution {

    // O(N^2) Time, O(N^2) Space - Optimal: Index Grouping
    public static void diagonalTraversal_optimal(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return;
        int R = matrix.length;
        int C = matrix[0].length;
        
        // TreeMap ensures that the diagonals are processed in increasing order of sum (i+j)
        Map<Integer, List<Integer>> diagonals = new TreeMap<>();

        // 1. Group elements by the sum of their indices (O(N^2))
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                diagonals.putIfAbsent(i + j, new ArrayList<>());
                diagonals.get(i + j).add(matrix[i][j]);
            }
        }

        // 2. Traverse the diagonals (O(N^2))
        List<Integer> result = new ArrayList<>();
        boolean directionUp = true; // Controls alternating reversal

        for (Map.Entry<Integer, List<Integer>> entry : diagonals.entrySet()) {
            List<Integer> currentDiagonal = entry.getValue();
            
            // Reverse the list if the problem requires alternating directions
            if (directionUp) {
                Collections.reverse(currentDiagonal);
            }
            
            result.addAll(currentDiagonal);
            
            // Flip direction
            directionUp = !directionUp;
        }

        // Print the space-separated output
        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i) + (i == result.size() - 1 ? "" : " "));
        }
        System.out.println();
    }
}