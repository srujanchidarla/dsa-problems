import java.util.ArrayList;
import java.util.List;

class Solution {
    
    // Optimized: O(N * N!) Time, O(N * N!) Space - Backtracking with Visited Array
    public List<List<Integer>> permutations_optimal(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        backtrack(nums, new ArrayList<>(), visited, results);
        return results;
    }

    private void backtrack(int[] nums, List<Integer> current_permutation, boolean[] visited, List<List<Integer>> results) {
        if (current_permutation.size() == nums.length) {
            results.add(new ArrayList<>(current_permutation));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                // 1. Choose
                visited[i] = true;
                current_permutation.add(nums[i]);
                
                // 2. Recurse
                backtrack(nums, current_permutation, visited, results);
                
                // 3. Backtrack
                current_permutation.remove(current_permutation.size() - 1);
                visited[i] = false;
            }
        }
    }
    
    // Brute Force: O(N * N!) - The swap method is an alternative approach.
    public List<List<Integer>> permutations_brute(int[] nums) {
        // For simplicity and clarity, we rely on the optimal method structure.
        return permutations_optimal(nums);
    }
}