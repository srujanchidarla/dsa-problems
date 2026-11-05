class SolutionBruteForce {
    // O(n * m) time | O(1) space — re-scan t from the start for every character of s.
    public boolean isSubsequence(String s, String t) {
        int last = -1;
        for (int i = 0; i < s.length(); i++) {
            boolean found = false;
            for (int j = 0; j < t.length(); j++) {
                if (j > last && t.charAt(j) == s.charAt(i)) {
                    last = j;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
}

class Solution {
    // O(n + m) time | O(1) space — two pointers, one pass.
    public boolean isSubsequence(String s, String t) {
        int i = 0;
        for (int j = 0; j < t.length(); j++) {
            if (i < s.length() && s.charAt(i) == t.charAt(j)) i++;
        }
        return i == s.length();
    }
}
