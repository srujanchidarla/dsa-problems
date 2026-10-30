class SolutionBruteForce {
    // O(n) time | O(n) space — convert to a number, add 1, convert back.
    // (Uses long; overflows for very long inputs — the naive idea.)
    public int[] plusOne(int[] digits) {
        long number = 0;
        for (int d : digits) number = number * 10 + d;
        number += 1;
        String s = Long.toString(number);
        int[] ans = new int[s.length()];
        for (int i = 0; i < s.length(); i++) ans[i] = s.charAt(i) - '0';
        return ans;
    }
}

class Solution {
    // O(n) time | O(1) extra space — carry from the right.
    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        int[] ans = new int[digits.length + 1];
        ans[0] = 1;
        return ans;
    }
}
