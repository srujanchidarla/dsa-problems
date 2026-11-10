class SolutionBruteForce {
    // O(n * m) time | O(1) space — try every start, compare char by char.
    public int strStr(String haystack, String needle) {
        int n = haystack.length(), m = needle.length();
        for (int i = 0; i <= n - m; i++) {
            boolean match = true;
            for (int j = 0; j < m; j++) {
                if (haystack.charAt(i + j) != needle.charAt(j)) {
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }
        return -1;
    }
}

class Solution {
    // O(n + m) time | O(m) space — KMP with the prefix function (LPS).
    public int strStr(String haystack, String needle) {
        if (needle.isEmpty()) return 0;
        // Build LPS: lps[k] = longest proper prefix of needle[0..k]
        // that is also a suffix of needle[0..k].
        int[] lps = new int[needle.length()];
        int length = 0, i = 1;
        while (i < needle.length()) {
            if (needle.charAt(i) == needle.charAt(length)) {
                lps[i++] = ++length;
            } else if (length > 0) {
                length = lps[length - 1];
            } else {
                lps[i++] = 0;
            }
        }
        // Search: j = how much of needle is currently matched.
        int j = 0;
        i = 0;
        while (i < haystack.length()) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
                if (j == needle.length()) return i - j;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return -1;
    }
}
