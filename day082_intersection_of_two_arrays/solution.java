import java.util.HashSet;
import java.util.Set;

class SolutionBruteForce {
    // O(n * m) time | O(n) space — for each value, linear-scan the other array.
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> out = new HashSet<>();
        for (int x : nums1) {
            for (int y : nums2) {
                if (x == y) out.add(x);
            }
        }
        return out.stream().mapToInt(Integer::intValue).toArray();
    }
}

class Solution {
    // O(n + m) time | O(m) space — hash set of nums2, keep matching values.
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> s2 = new HashSet<>();
        for (int y : nums2) s2.add(y);
        Set<Integer> out = new HashSet<>();
        for (int x : nums1) {
            if (s2.contains(x)) out.add(x);
        }
        return out.stream().mapToInt(Integer::intValue).toArray();
    }
}
