import java.util.Scanner;

class Solution {
    
    // Optimized: O(1) Time, O(1) Space - Bitwise Trick
    public boolean isPowerOfTwo_optimal(int n) {
        // Check 1: Must be positive
        // Check 2: N & (N - 1) == 0 means only one bit was set
        return n > 0 && (n & (n - 1)) == 0;
    }

    // Brute Force: O(log N) Time, O(1) Space - Repeated Division
    public boolean isPowerOfTwo_brute(int n) {
        if (n <= 0) return false;
        
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }
}