import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Stack;

class Solution {

    // Optimized: O(N) Time, O(N) Space - Stack and Hash Map
    public boolean isValid_optimal(String s) {
        // Hash Map for O(1) lookup: closer -> opener
        Map<Character, Character> mappings = new HashMap<>();
        mappings.put(')', '(');
        mappings.put('}', '{');
        mappings.put(']', '[');
        
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (mappings.containsValue(c)) {
                // Case 1: Opener -> Push to stack
                stack.push(c);
            } else if (mappings.containsKey(c)) {
                // Case 2: Closer
                
                // If stack is empty (unmatched closer) or mismatch
                if (stack.isEmpty() || stack.pop() != mappings.get(c)) {
                    return false;
                }
            }
            // Ignore other characters
        }
        
        // Final check: Valid only if the stack is empty
        return stack.isEmpty();
    }

    // Brute Force: O(N) Time - The stack approach is the standard linear method.
    public boolean isValid_brute(String s) {
        return isValid_optimal(s);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String s = scanner.nextLine();
        
        Solution solution = new Solution();
        if (solution.isValid_optimal(s)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
        scanner.close();
    }
}