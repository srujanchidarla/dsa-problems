import java.util.HashSet;

class SolutionBruteForce {
    // O(n^2) time | O(1) space — count every value 1..n by re-scanning.
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int duplicate = -1, missing = -1;
        for (int x = 1; x <= n; x++) {
            int count = 0;
            for (int v : nums) if (v == x) count++;
            if (count == 2) duplicate = x;
            else if (count == 0) missing = x;
        }
        return new int[]{duplicate, missing};
    }
}

class Solution {
    // O(n) time | O(n) space — find the duplicate with a set, the missing with sums.
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        HashSet<Integer> seen = new HashSet<>();
        int duplicate = -1;
        for (int v : nums) {
            if (!seen.add(v)) duplicate = v;
        }
        int expected = n * (n + 1) / 2;
        int sum = 0;
        for (int v : nums) sum += v;
        int missing = expected - (sum - duplicate);
        return new int[]{duplicate, missing};
    }
}
