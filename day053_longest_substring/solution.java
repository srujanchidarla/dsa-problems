import java.util.HashSet;
import java.util.Set;

class SolutionBruteForce {
    // O(n^2) time | O(n) space — extend from each start until a repeat.
    public int lengthOfLongestSubstring(String s) {
        int best = 0;
        for (int i = 0; i < s.length(); i++) {
            Set<Character> seen = new HashSet<>();
            for (int j = i; j < s.length(); j++) {
                if (seen.contains(s.charAt(j))) break;
                seen.add(s.charAt(j));
                best = Math.max(best, j - i + 1);
            }
        }
        return best;
    }
}

class Solution {
    // O(n) time | O(n) space — sliding window with a set.
    public int lengthOfLongestSubstring(String s) {
        Set<Character> window = new HashSet<>();
        int l = 0, best = 0;
        for (int r = 0; r < s.length(); r++) {
            while (window.contains(s.charAt(r))) {
                window.remove(s.charAt(l));
                l++;
            }
            window.add(s.charAt(r));
            best = Math.max(best, r - l + 1);
        }
        return best;
    }
}
