import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Result {

    /**
     * Optimized Approach: Uses a HashMap for frequency counting.
     * Time Complexity: O(N + M)
     * Space Complexity: O(U) where U is the number of unique strings.
     */
    public static List<Integer> matchingStringsOptimized(List<String> stringList, List<String> queries) {
        // 1. Build Frequency Map (O(N))
        Map<String, Integer> freqMap = new HashMap<>();
        for (String s : stringList) {
            // getOrDefault is a concise way to handle the increment
            freqMap.put(s, freqMap.getOrDefault(s, 0) + 1);
        }

        // 2. Process Queries (O(M))
        List<Integer> results = new ArrayList<>();
        for (String q : queries) {
            // getOrDefault returns 0 if the key is not found (O(1) average lookup)
            results.add(freqMap.getOrDefault(q, 0));
        }

        return results;
    }

    /**
     * Brute Force Approach: Uses nested loops for matching.
     * Time Complexity: O(N * M)
     * Space Complexity: O(1)
     */
    public static List<Integer> matchingStringsBruteForce(List<String> stringList, List<String> queries) {
        List<Integer> results = new ArrayList<>();
        
        // Iterate through every query (O(M))
        for (String query : queries) {
            int count = 0;
            // For every query, iterate through every string in the list (O(N))
            for (String s : stringList) {
                if (query.equals(s)) {
                    count++;
                }
            }
            results.add(count);
        }
        return results;
    }
}