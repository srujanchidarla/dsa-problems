import java.util.Scanner;
import java.util.Arrays;

class Solution {

    // O(1) Time, O(1) Space - Optimal
    public static boolean isTriangleValid_optimal(int a, int b, int c) {
        if (a <= 0 || b <= 0 || c <= 0) return false;
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    // O(1) Time, O(1) Space - Brute (Uses sorting which is O(1) for 3 elements)
    public static boolean isTriangleValid_brute(int a, int b, int c) {
        int[] sides = {a, b, c};
        Arrays.sort(sides); // Sorting 3 elements is constant time
        
        if (sides[0] <= 0) return false;
        // Check if sum of two smaller sides > largest side
        return sides[0] + sides[1] > sides[2];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        
        if (isTriangleValid_optimal(a, b, c)) {
            System.out.println("Valid");
        } else {
            System.out.println("Invalid");
        }
        scanner.close();
    }
}