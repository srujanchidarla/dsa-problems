import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

class Solution {

    // Optimized: O(N log N) Time, O(N) Space - Sorting and Greedy Merge
    public int[][] merge_optimal(int[][] intervals) {
        if (intervals.length <= 1) {
            return intervals;
        }

        // 1. Sort by start time (O(N log N))
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));

        List<int[]> merged = new ArrayList<>();
        int[] currentInterval = intervals[0];
        merged.add(currentInterval);

        for (int[] nextInterval : intervals) {
            int currentEnd = currentInterval[1];
            int nextStart = nextInterval[0];
            int nextEnd = nextInterval[1];

            // Check for overlap: current end >= next start
            if (currentEnd >= nextStart) {
                // Merge: Update the end time of the currentInterval pointer
                currentInterval[1] = Math.max(currentEnd, nextEnd);
            } else {
                // No overlap: Start a new currentInterval
                currentInterval = nextInterval;
                merged.add(currentInterval);
            }
        }

        return merged.toArray(new int[merged.size()][]);
    }
}