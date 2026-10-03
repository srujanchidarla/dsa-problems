import java.util.Scanner;

public class solution {

    // ─────────────────────────────────────────────────────────────────────
    // OPTIMIZED — O(1) time | O(1) space
    // 0 if same square, 1 if same row/col/diagonal, else 2
    // ─────────────────────────────────────────────────────────────────────
    static int minQueenMoves(int[] source, int[] target) {
        int dr = Math.abs(source[0] - target[0]);  // row distance
        int dc = Math.abs(source[1] - target[1]);  // column distance

        if (dr == 0 && dc == 0) return 0;           // already there
        if (dr == 0 || dc == 0 || dr == dc) return 1; // row / column / diagonal
        return 2;                                    // row move + column move
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] source = {sc.nextInt(), sc.nextInt()};
        int[] target = {sc.nextInt(), sc.nextInt()};

        System.out.println(minQueenMoves(source, target));

        sc.close();
    }
}
