import java.util.*;

class SolutionBruteForce {
    // O(n log n) time | O(n) space — count, then sort by frequency.
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int v : nums) freq.put(v, freq.getOrDefault(v, 0) + 1);
        List<Integer> keys = new ArrayList<>(freq.keySet());
        keys.sort((a, b) -> freq.get(b) - freq.get(a));
        int[] result = new int[k];
        for (int i = 0; i < k; i++) result[i] = keys.get(i);
        return result;
    }
}

class Solution {
    // O(n) time | O(n) space — bucket sort by frequency.
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int v : nums) freq.put(v, freq.getOrDefault(v, 0) + 1);
        List<List<Integer>> buckets = new ArrayList<>();
        for (int i = 0; i <= nums.length; i++) buckets.add(new ArrayList<>());
        for (Map.Entry<Integer, Integer> e : freq.entrySet()) {
            buckets.get(e.getValue()).add(e.getKey());   // frequency IS the index
        }
        int[] result = new int[k];
        int filled = 0;
        for (int count = nums.length; count >= 1 && filled < k; count--) {
            for (int num : buckets.get(count)) {
                result[filled++] = num;
                if (filled == k) return result;
            }
        }
        return result;
    }
}
