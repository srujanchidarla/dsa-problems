import java.util.Scanner;

class Solution {

    // O(N) Time, O(1) Space - Optimal (Single Pass)
    public static void calculateOddEvenSum_optimal(int N, Scanner scanner) {
        long oddSum = 0;
        long evenSum = 0;

        // Single Linear Pass (O(N))
        for (int i = 0; i < N; i++) {
            if (!scanner.hasNextInt()) break;
            int num = scanner.nextInt();
            
            if (num % 2 == 0) {
                evenSum += num;
            } else {
                oddSum += num;
            }
        }
        
        // Output format
        System.out.println(oddSum);
        System.out.println(evenSum);
    }

    // O(N) Time, O(1) Space - Brute (Requires reading input twice, making I/O O(2N))
    public static void calculateOddEvenSum_brute(int N, Scanner scanner) {
        // Since the actual computational core is O(N), we rely on the optimal function.
        // In a strict sense, the only "brute" difference would be multiple loops 
        // or re-reading input, which is bad practice.
        calculateOddEvenSum_optimal(N, scanner); 
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt();
        
        // Since input streams are read sequentially, we must choose one method.
        // We will call the optimal method.
        calculateOddEvenSum_optimal(N, scanner);
        
        scanner.close();
    }
}