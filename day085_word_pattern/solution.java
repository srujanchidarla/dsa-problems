import java.util.HashMap;
import java.util.Map;

class SolutionBruteForce {
    // O(n^2) time | O(1) space — same letter exactly when same word, for every pair.
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) return false;
        for (int i = 0; i < pattern.length(); i++) {
            for (int j = 0; j < pattern.length(); j++) {
                if ((pattern.charAt(i) == pattern.charAt(j)) != words[i].equals(words[j])) return false;
            }
        }
        return true;
    }
}

class Solution {
    // O(n) time | O(n) space — two maps enforce the bijection in one pass.
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) return false;
        Map<Character, String> p2w = new HashMap<>();
        Map<String, Character> w2p = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern.charAt(i);
            String w = words[i];
            if (p2w.containsKey(ch) && !p2w.get(ch).equals(w)) return false;
            if (w2p.containsKey(w) && w2p.get(w) != ch) return false;
            p2w.put(ch, w);
            w2p.put(w, ch);
        }
        return true;
    }
}
