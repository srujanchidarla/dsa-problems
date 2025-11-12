import java.util.HashMap;
import java.util.Map;

class Solution {
    
    // Optimized: O(N) Time, O(1) Space - XOR Application
    public int singleNumber_optimal(int[] nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }

    // Brute Force: O(N) Time, O(N) Space - Hash Map/Set
    public int singleNumber_brute(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int num : nums) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }
        
        for (int num : nums) {
            if (counts.get(num) == 1) {
                return num;
            }
        }
        return -1;
    }
}