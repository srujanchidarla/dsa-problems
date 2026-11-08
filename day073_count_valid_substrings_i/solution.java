class SolutionBruteForce {
    // O(n^2) time | O(1) space — check every substring, stop early at "abc".
    public int countValidSubstrings(String s) {
        int n = s.length(), count = 0;
        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) {
                if (end - start >= 2 && s.charAt(end - 2) == 'a'
                        && s.charAt(end - 1) == 'b' && s.charAt(end) == 'c') break;
                count++;
            }
        }
        return count;
    }
}

class Solution {
    // O(n) time | O(1) space — sliding left boundary past the last "abc".
    public int countValidSubstrings(String s) {
        int ans = 0, left = 0;
        for (int r = 0; r < s.length(); r++) {
            if (r >= 2 && s.charAt(r - 2) == 'a'
                    && s.charAt(r - 1) == 'b' && s.charAt(r) == 'c') {
                left = Math.max(left, r - 1);
            }
            ans += r - left + 1;
        }
        return ans;
    }
}
