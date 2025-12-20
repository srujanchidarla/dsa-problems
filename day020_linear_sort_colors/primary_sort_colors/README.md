---
dayNumber: 20
title: "Sort Colors (Dutch National Flag)"
platform: "LeetCode"
link: "https://leetcode.com/problems/sort-colors/"
difficulty: "Medium"
pattern: "Three-Way Partitioning / Two Pointers"
approach: "Use three pointers (low, mid, high) to maintain three regions: [0, low-1] are 0s, [low, mid-1] are 1s, and [high+1, N-1] are 2s. Process elements at 'mid' in a single pass."
optimized: "O(N)"
bruteforce: "O(N log N)"
space: "O(1)"
date: "2025-11-17"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - sorting
  - linear-time
  - two-pointers
---

# Sort Colors (Dutch National Flag)

**Platform:** LeetCode | **Difficulty:** Medium | **Pattern:** Three-Way Partitioning

---

## Problem Description

Given an array `nums` with $n$ objects colored red, white, or blue (represented by the integers 0, 1, and 2, respectively), sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

## Approaches

### 1. Dutch National Flag Algorithm (Optimal) - $O(N)$ ⭐

**Idea:** This specialized algorithm sorts elements into three partitions in a single pass, achieving linear time complexity, which is faster than any comparison-based sort ($O(N \log N)$).

1.  Initialize three pointers: `low = 0`, `mid = 0`, `high = N-1`.
2.  Iterate while `mid <= high`.
    - If `nums[mid] == 0`: Swap `nums[mid]` with `nums[low]`. Increment `low` and `mid`.
    - If `nums[mid] == 1`: Increment `mid`.
    - If `nums[mid] == 2`: Swap `nums[mid]` with `nums[high]`. Decrement `high`. (Do **not** increment `mid` because the swapped element at `mid` needs to be checked).

### 2. Brute Force (Comparison Sort) - $O(N \log N)$

**Idea:** Simply use a standard general-purpose sorting algorithm (like Quick Sort or Merge Sort). This is unnecessary overkill since the input domain is limited to only three values.

---
