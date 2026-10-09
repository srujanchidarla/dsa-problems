import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class SolutionBruteForce {
    // O(n^2 * k log k) — compare each word against every group.
    private boolean isAnagram(String a, String b) {
        if (a.length() != b.length()) return false;
        char[] x = a.toCharArray(), y = b.toCharArray();
        Arrays.sort(x);
        Arrays.sort(y);
        return Arrays.equals(x, y);
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> groups = new ArrayList<>();
        for (String w : strs) {
            boolean placed = false;
            for (List<String> g : groups) {
                if (isAnagram(w, g.get(0))) {
                    g.add(w);
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                List<String> ng = new ArrayList<>();
                ng.add(w);
                groups.add(ng);
            }
        }
        return groups;
    }
}

class Solution {
    // O(n * k log k) — sorted canonical key in a hash map.
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for (String w : strs) {
            char[] chars = w.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(w);
        }
        return new ArrayList<>(map.values());
    }
}
