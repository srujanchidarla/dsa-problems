import java.util.Scanner;

class Solution {

    // Optimal: O(log(min(A,B))) Time - Euclidean Algorithm (Recursive)
    public static int gcd_recursive(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd_recursive(b, a % b);
    }

    // Alternative Optimal: O(log(min(A,B))) Time - Euclidean Algorithm (Iterative)
    public static int gcd_iterative(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int A = scanner.nextInt();
        if (!scanner.hasNextInt()) return;
        int B = scanner.nextInt();
        
        System.out.println("GCD: " + gcd_iterative(A, B));
        scanner.close();
    }
}