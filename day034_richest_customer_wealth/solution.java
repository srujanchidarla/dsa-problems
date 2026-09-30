import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(m × n) time | O(1) space
    // Sum each row, keep a running max
    // ─────────────────────────────────────────────────────────────────────
    static int maximumWealth(int[][] accounts) {
        int best = 0;                            // richest wealth so far

        for (int[] customer : accounts) {
            int wealth = 0;
            for (int money : customer) {
                wealth += money;                 // total for this customer
            }
            best = Math.max(best, wealth);       // update running max
        }

        return best;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();                    // number of customers
        int n = sc.nextInt();                    // number of banks
        int[][] accounts = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                accounts[i][j] = sc.nextInt();
            }
        }

        System.out.println(maximumWealth(accounts));

        sc.close();
    }
}
