import java.util.Scanner;

class Solution {

    // O(M) Time, O(1) Space - Greedy Single Pass
    public static void solve_alternate_seating() {
        Scanner scanner = new Scanner(System.in);
        
        if (!scanner.hasNextInt()) return;
        int N = scanner.nextInt(); // People needed
        
        if (!scanner.hasNextInt()) return;
        int M = scanner.nextInt(); // Total seats

        int[] seats = new int[M];
        for (int i = 0; i < M; i++) {
            if (!scanner.hasNextInt()) return;
            seats[i] = scanner.nextInt(); // Read seat configuration
        }

        int peopleSeated = 0;

        for (int i = 0; i < M; i++) {
            if (peopleSeated >= N) break;

            // Check 1: Seat must be vacant
            if (seats[i] == 0) {
                
                // Check 2: Left neighbor
                boolean leftEmpty = (i == 0) || (seats[i - 1] == 0);
                
                // Check 3: Right neighbor
                boolean rightEmpty = (i == M - 1) || (seats[i + 1] == 0);
                
                if (leftEmpty && rightEmpty) {
                    // Greedily take the seat
                    seats[i] = 1; 
                    peopleSeated++;
                }
            }
        }

        if (peopleSeated >= N) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        
        scanner.close();
    }

    public static void main(String[] args) {
        solve_alternate_seating();
    }
}