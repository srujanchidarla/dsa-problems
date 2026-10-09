class SolutionBruteForce {
    // O(n) time | O(n) space — filter, then compare with reverse.
    public boolean isPalindrome(String s) {
        StringBuilder f = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (Character.isLetterOrDigit(s.charAt(i))) {
                f.append(Character.toLowerCase(s.charAt(i)));
            }
        }
        String t = f.toString();
        return t.equals(f.reverse().toString());
    }
}

class Solution {
    // O(n) time | O(1) space — two pointers inward.
    public boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !Character.isLetterOrDigit(s.charAt(i))) i++;
            while (j > i && !Character.isLetterOrDigit(s.charAt(j))) j--;
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}
