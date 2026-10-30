class SolutionBruteForce {
    // O(n * m^2) time — try every prefix of the shortest word, longest first.
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        String shortest = strs[0];
        for (String w : strs) if (w.length() < shortest.length()) shortest = w;
        for (int len = shortest.length(); len >= 0; len--) {
            String prefix = shortest.substring(0, len);
            boolean ok = true;
            for (String w : strs) if (!w.startsWith(prefix)) { ok = false; break; }
            if (ok) return prefix;
        }
        return "";
    }
}

class Solution {
    // O(S) time | O(1) extra space — vertical scan, stop at first mismatch.
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (i >= strs[j].length() || strs[j].charAt(i) != c) {
                    return strs[0].substring(0, i);
                }
            }
        }
        return strs[0];
    }
}
