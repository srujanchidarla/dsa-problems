import java.util.ArrayList;
import java.util.List;

class Solution {
    
    // Optimized: O(N * 2^N) Time, O(N * 2^N) Space - Backtracking/DFS
    public List<List<Integer>> subsets_optimal(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        backtrack(nums, 0, new ArrayList<>(), results);
        return results;
    }

    private void backtrack(int[] nums, int start, List<Integer> current_subset, List<List<Integer>> results) {
        // Add the subset found at this depth
        results.add(new ArrayList<>(current_subset));

        for (int i = start; i < nums.length; i++) {
            // 1. Choose
            current_subset.add(nums[i]);
            
            // 2. Recurse
            backtrack(nums, i + 1, current_subset, results);
            
            // 3. Backtrack
            current_subset.remove(current_subset.size() - 1);
        }
    }
    
    // Alternative Optimal: O(N * 2^N) Time, O(N * 2^N) Space - Bit Manipulation
    public List<List<Integer>> subsets_bit_manipulation(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        int N = nums.length;
        int total_subsets = 1 << N; 

        for (int i = 0; i < total_subsets; i++) {
            List<Integer> subset = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                // Check if the j-th bit is set
                if (((i >> j) & 1) == 1) {
                    subset.add(nums[j]);
                }
            }
            results.add(subset);
        }
        return results;
    }
}