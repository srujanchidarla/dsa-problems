import java.util.Scanner;

class Solution {

    // O(N) Time, O(N) Space - Optimal (Single Pass with Counting)
    public static void solve_compress_string() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String S = scanner.nextLine();
        
        if (S.isEmpty()) {
            System.out.println("");
            scanner.close();
            return;
        }

        StringBuilder compressed = new StringBuilder();
        int N = S.length();
        int i = 0;

        while (i < N) {
            char currentChar = S.charAt(i);
            int count = 0;
            int j = i;

            // Count the consecutive run
            while (j < N && S.charAt(j) == currentChar) {
                count++;
                j++;
            }
            
            // Append character and count
            compressed.append(currentChar).append(count);
            
            // Move i to the start of the next run
            i = j;
        }
        
        System.out.println(compressed.toString());
        scanner.close();
    }

    public static void main(String[] args) {
        solve_compress_string();
    }
}