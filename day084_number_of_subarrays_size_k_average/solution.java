class SolutionBruteForce {
    // O(n * k) time | O(1) space — re-sum every window of size k.
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int count = 0;
        for (int i = 0; i + k <= arr.length; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) sum += arr[j];
            if (sum / (double) k >= threshold) count++;
        }
        return count;
    }
}

class Solution {
    // O(n) time | O(1) space — sliding window; compare sum against k * threshold.
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int window = 0;
        for (int i = 0; i < k; i++) window += arr[i];
        int count = window >= k * threshold ? 1 : 0;
        for (int i = k; i < arr.length; i++) {
            window += arr[i] - arr[i - k];
            if (window >= k * threshold) count++;
        }
        return count;
    }
}
