class SolutionBruteForce {
    // O(n^2) time | O(n) space — rescan and delete pairs until nothing changes.
    public String removeDuplicates(String s) {
        boolean changed = true;
        while (changed) {
            changed = false;
            StringBuilder out = new StringBuilder();
            int i = 0;
            while (i < s.length()) {
                if (i + 1 < s.length() && s.charAt(i) == s.charAt(i + 1)) {
                    i += 2;
                    changed = true;
                } else {
                    out.append(s.charAt(i));
                    i++;
                }
            }
            s = out.toString();
        }
        return s;
    }
}

class Solution {
    // O(n) time | O(n) space — stack: a matching top cancels the pair.
    public String removeDuplicates(String s) {
        StringBuilder stack = new StringBuilder();
        for (char ch : s.toCharArray()) {
            int n = stack.length();
            if (n > 0 && stack.charAt(n - 1) == ch) {
                stack.deleteCharAt(n - 1);
            } else {
                stack.append(ch);
            }
        }
        return stack.toString();
    }
}
