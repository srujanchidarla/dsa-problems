import sys
from typing import List

class Solution:
    # Optimized: O(N log N) Time, O(N) Space - Sorting and Greedy Merge
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []

        # 1. Sort the intervals by the start time (O(N log N))
        intervals.sort(key=lambda x: x[0])
        
        merged = []
        current_start, current_end = intervals[0]

        for i in range(1, len(intervals)):
            next_start, next_end = intervals[i]
            
            # Check for overlap: current end >= next start
            if current_end >= next_start:
                # Merge: Update the end time to the maximum of the two ends
                current_end = max(current_end, next_end)
            else:
                # No overlap: Add the merged interval and start a new one
                merged.append([current_start, current_end])
                current_start, current_end = next_start, next_end

        # Add the last merged interval
        merged.append([current_start, current_end])
        return merged

# The Brute Force O(N^2) solution is highly discouraged and complex to implement correctly
# due to repeated merging passes.