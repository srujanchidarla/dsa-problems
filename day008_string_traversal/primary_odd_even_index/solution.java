import java.util.Scanner;

class Solution {

    // O(N) Time, O(N) Space - Optimal (Single Pass)
    public static void solve_odd_even_index() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String S = scanner.nextLine();
        
        StringBuilder evenChars = new StringBuilder();
        StringBuilder oddChars = new StringBuilder();

        for (int i = 0; i < S.length(); i++) {
            if (i % 2 == 0) {
                evenChars.append(S.charAt(i));
            } else {
                oddChars.append(S.charAt(i));
            }
        }
        
        System.out.println(evenChars.toString());
        System.out.println(oddChars.toString());
        scanner.close();
    }

    public static void main(String[] args) {
        solve_odd_even_index();
    }
}