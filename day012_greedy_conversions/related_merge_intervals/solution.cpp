#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Optimized: O(N log N) Time, O(N) Space - Sorting and Greedy Merge
    vector<vector<int>> merge_optimal(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // 1. Sort by start time (O(N log N))
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        merged.push_back(intervals[0]); // Start with the first interval

        for (int i = 1; i < intervals.size(); ++i) {
            // Get the last merged interval's end
            int last_end = merged.back()[1];
            // Get the current interval's start and end
            int current_start = intervals[i][0];
            int current_end = intervals[i][1];

            // Check for overlap: current start <= last end
            if (current_start <= last_end) {
                // Merge: Update the last merged interval's end time
                merged.back()[1] = max(last_end, current_end);
            } else {
                // No overlap: Add the current interval as a new entry
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};