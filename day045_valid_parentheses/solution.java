import java.util.Stack;

class SolutionBruteForce {
    // O(n^2) time | O(n) space — repeatedly strip matching pairs.
    public boolean isValid(String s) {
        String prev;
        do {
            prev = s;
            s = s.replace("()", "").replace("{}", "").replace("[]", "");
        } while (!prev.equals(s));
        return s.isEmpty();
    }
}

class Solution {
    // O(n) time | O(n) space — stack matching.
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
                continue;
            }
            if (stack.isEmpty()) return false;
            char top = stack.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
        return stack.isEmpty();
    }
}
