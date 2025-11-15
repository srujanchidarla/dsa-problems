import java.util.Scanner;

class Solution {
    // Optimized (1 to N): Post-recursion print
    public static void print_1_to_N_optimal(int n) {
        if (n == 0) {
            return;
        }
        print_1_to_N_optimal(n - 1);
        System.out.print(n + " ");
    }

    // Brute Force (N to 1): Pre-recursion print
    public static void print_N_to_1_brute(int n) {
        if (n == 0) {
            return;
        }
        System.out.print(n + " ");
        print_N_to_1_brute(n - 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt();
        
        System.out.print("N to 1 (Brute): ");
        print_N_to_1_brute(N);
        System.out.print("\n1 to N (Optimal): ");
        print_1_to_N_optimal(N);
        System.out.println();
        scanner.close();
    }
}