import java.util.Scanner;

class Solution {

    // Optimized: O(N) Time, O(1) Space (Fixed size array for a-z)
    public int firstUniqChar_optimal(String s) {
        // Use an array of size 26 for O(1) space/lookup
        int[] counts = new int[26];

        // Pass 1: Count frequencies (O(N))
        for (char c : s.toCharArray()) {
            counts[c - 'a']++;
        }

        // Pass 2: Find the first character with count == 1 (O(N))
        for (int i = 0; i < s.length(); i++) {
            if (counts[s.charAt(i) - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }

    // Brute Force: O(N^2) Time
    public int firstUniqChar_brute(String s) {
        int N = s.length();
        for (int i = 0; i < N; i++) {
            boolean repeated = false;
            for (int j = 0; j < N; j++) {
                if (i != j && s.charAt(i) == s.charAt(j)) {
                    repeated = true;
                    break;
                }
            }
            if (!repeated) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String s = scanner.nextLine();
        
        Solution solution = new Solution();
        System.out.println(solution.firstUniqChar_optimal(s));
        scanner.close();
    }
}