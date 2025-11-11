---
dayNumber: 12
title: "Merge Intervals"
platform: "LeetCode"
link: "https://leetcode.com/problems/merge-intervals/"
difficulty: "Medium"
pattern: "Interval Management / Sorting"
approach: "Sort the intervals by their start time. Iterate through the sorted list, merging the current interval with the last merged interval if they overlap."
optimized: "O(N log N)"
bruteforce: "O(N²)"
space: "O(N)"
date: "2025-11-09"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - array
  - greedy
  - sorting
  - intervals
---

# Merge Intervals

**Platform:** LeetCode | **Difficulty:** Medium | **Pattern:** Interval Management

---

## Problem Description

Given an array of intervals, where $intervals[i] = [start_i, end_i]$, merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

## Approaches

### 1. Sorting and Greedy Merge (Optimal) - $O(N \log N)$ ⭐

**Idea:** This is the core algorithm for interval management. Sorting ensures that as we iterate, any potential overlaps must occur only with the _last_ merged interval.

1.  **Sort** the intervals based on their start time ($\text{O}(N \log N)$).
2.  Initialize the result list with the first interval.
3.  Iterate through the rest of the sorted intervals:
    - If the current interval overlaps with the last merged interval (i.e., its start $\le$ last merged end), **merge** by updating the last merged end to $\max(\text{last end}, \text{current end})$.
    - If there is no overlap, add the current interval to the result list.

### 2. Brute Force - $O(N^2)$

**Idea:** Compare every interval against every other interval to see if they overlap, and merge them repeatedly until no more merges are possible. This results in slow performance due to redundant checks.

---
