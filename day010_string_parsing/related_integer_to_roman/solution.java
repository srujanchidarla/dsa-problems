import java.util.Scanner;

class Solution {

    private final int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    private final String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // O(1) Time, O(1) Space - Optimal (Greedy Lookup)
    public String intToRoman_optimal(int num) {
        StringBuilder result = new StringBuilder();
        
        for (int i = 0; i < values.length && num > 0; i++) {
            // Greedily append the symbol
            while (num >= values[i]) {
                result.append(symbols[i]);
                num -= values[i];
            }
        }
        return result.toString();
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int num = scanner.nextInt();
        
        Solution solution = new Solution();
        System.out.println(solution.intToRoman_optimal(num));
        scanner.close();
    }
}