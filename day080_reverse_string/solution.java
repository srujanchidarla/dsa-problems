class SolutionBruteForce {
    // O(n) time | O(n) space — build a reversed copy, then copy it back.
    public void reverseString(char[] s) {
        char[] rev = new char[s.length];
        for (int i = 0; i < s.length; i++) rev[i] = s[s.length - 1 - i];
        System.arraycopy(rev, 0, s, 0, s.length);
    }
}

class Solution {
    // O(n) time | O(1) space — two pointers swap from both ends.
    public void reverseString(char[] s) {
        int left = 0, right = s.length - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
}
