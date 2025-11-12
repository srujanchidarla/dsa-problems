import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Solution {

    // O(sqrt(N)) Time, O(1) Space - Optimal Primality Check
    public static boolean isPrime_optimal(int N) {
        if (N <= 1) return false;
        if (N <= 3) return true;
        
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                return false;
            }
        }
        return true;
    }

    // O(N) Time, O(1) Space - Brute Force Primality Check
    public static boolean isPrime_brute(int N) {
        if (N <= 1) return false;
        for (int i = 2; i < N; i++) {
            if (N % i == 0) {
                return false;
            }
        }
        return true;
    }

    // O(sqrt(N)) Time, O(sqrt(N)) Space - Optimized Divisor Printing
    public static void printDivisors_optimal(int N) {
        if (N <= 0) return;
        ArrayList<Integer> divisors = new ArrayList<>();
        
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                divisors.add(i);
                // If i and N/i are different, add the second factor
                if (i * i != N) {
                    divisors.add(N / i);
                }
            }
        }
        
        Collections.sort(divisors);
        System.out.print("Divisors: ");
        for (int d : divisors) {
            System.out.print(d + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt();
        
        System.out.println("Is Prime: " + (isPrime_optimal(N) ? "YES" : "NO"));
        printDivisors_optimal(N);
        scanner.close();
    }
}