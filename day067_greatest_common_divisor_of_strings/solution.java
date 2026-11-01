class SolutionBruteForce {
    // O(n * m) time — try every divisor length, longest first.
    private boolean divides(String s, String t) {
        if (s.length() % t.length() != 0) return false;
        StringBuilder built = new StringBuilder();
        for (int i = 0; i < s.length() / t.length(); i++) built.append(t);
        return s.equals(built.toString());
    }

    public String gcdOfStrings(String str1, String str2) {
        int minLen = Math.min(str1.length(), str2.length());
        for (int len = minLen; len >= 1; len--) {
            if (str1.length() % len == 0 && str2.length() % len == 0) {
                String candidate = str1.substring(0, len);
                if (divides(str1, candidate) && divides(str2, candidate)) return candidate;
            }
        }
        return "";
    }
}

class Solution {
    // O(n + m) time — equal concatenations + gcd of the lengths.
    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1)) return "";
        return str1.substring(0, gcd(str1.length(), str2.length()));
    }
}
