class SolutionBruteForce {
    // O(n) time | O(n) space — split into words and take the last one.
    public int lengthOfLastWord(String s) {
        String[] words = s.trim().split("\\s+");
        return words[words.length - 1].length();
    }
}

class Solution {
    // O(n) time | O(1) space — walk backwards past trailing spaces, then count.
    public int lengthOfLastWord(String s) {
        int i = s.length() - 1;
        while (i >= 0 && s.charAt(i) == ' ') i--;
        int length = 0;
        while (i >= 0 && s.charAt(i) != ' ') {
            length++;
            i--;
        }
        return length;
    }
}
