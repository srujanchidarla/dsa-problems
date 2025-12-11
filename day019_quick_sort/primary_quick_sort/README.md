---
dayNumber: 19
title: "Quick Sort (Implementation)"
platform: "Custom"
link: "http://example.com/custom-quick-sort"
difficulty: "Medium"
pattern: "Partitioning"
approach: "Select a pivot element. Rearrange the array so all elements less than the pivot come before it, and all elements greater come after it. Recursively apply this to the sub-arrays."
optimized: "O(N log N)"
bruteforce: "O(N²)"
space: "O(log N)"
date: "2025-11-16"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - sorting
  - partitioning
  - in-place
---

# Quick Sort (Implementation)

**Platform:** Custom | **Difficulty:** Medium | **Pattern:** Partitioning

---

## Problem Description

Given an array of integers, sort the array using the **Quick Sort** algorithm. The implementation must include a robust **partitioning** scheme (e.g., Lomuto or Hoare) and handle recursion effectively.

## Approaches

### 1. Partitioning and Recursion (Optimal Average) - $O(N \log N)$ ⭐

**Idea:** Quick Sort's efficiency depends heavily on selecting a good pivot.

1.  **Partition:** Choose a pivot (ideally median-of-three or random). Rearrange the array elements around the pivot in $O(N)$ time.
2.  **Recursion:** Recursively call Quick Sort on the sub-array of elements smaller than the pivot and the sub-array of elements larger than the pivot.

### 2. Brute Force (Worst Case) - $O(N^2)$

**Idea:** If the pivot is always chosen poorly (e.g., always the smallest or largest element), the recursion tree becomes skewed (linear depth), leading to $O(N^2)$ performance. This typically happens if the input is already sorted and the first element is always chosen as the pivot.

---
