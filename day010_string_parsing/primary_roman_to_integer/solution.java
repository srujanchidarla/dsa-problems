import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Solution {
    
    private final Map<Character, Integer> romanMap = new HashMap<>() {{
        put('I', 1);
        put('V', 5);
        put('X', 10);
        put('L', 50);
        put('C', 100);
        put('D', 500);
        put('M', 1000);
    }};

    // Optimized: O(N) Time, O(1) Space - Right-to-Left Traversal (Cleaner Logic)
    public int romanToInt_optimal(String s) {
        if (s == null || s.isEmpty()) return 0;
        
        int total = romanMap.get(s.charAt(s.length() - 1)); // Start with the last character
        
        // Iterate from the second-to-last character backward
        for (int i = s.length() - 2; i >= 0; i--) {
            int currentVal = romanMap.get(s.charAt(i));
            int nextVal = romanMap.get(s.charAt(i+1));
            
            if (currentVal < nextVal) {
                total -= currentVal; // Subtraction case
            } else {
                total += currentVal; // Addition case
            }
        }
        return total;
    }

    // Brute Force: O(N) Time, O(1) Space - Left-to-Right Check (More complex index management)
    public int romanToInt_brute(String s) {
        int total = 0;
        int N = s.length();

        for (int i = 0; i < N; ++i) {
            int currentVal = romanMap.get(s.charAt(i));
            
            if (i < N - 1) {
                int nextVal = romanMap.get(s.charAt(i+1));
                
                // Check for subtraction case and handle the pair
                if (currentVal < nextVal) {
                    total += (nextVal - currentVal);
                    i++; // Crucial: Skip the next character
                    continue;
                }
            }
            // Default case: add the current character's value
            total += currentVal;
        }
        return total;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String s = scanner.nextLine();
        
        Solution solution = new Solution();
        int result = solution.romanToInt_optimal(s);
        System.out.println(result);
        scanner.close();
    }
}