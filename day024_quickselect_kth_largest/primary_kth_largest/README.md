---
dayNumber: 24
title: "Kth Largest Element (Quickselect)"
platform: "LeetCode"
link: "https://leetcode.com/problems/kth-largest-element-in-an-array/"
difficulty: "Medium"
pattern: "Quickselect / Partitioning"
approach: "Use the partitioning logic of Quick Sort. Instead of recursing into both halves, only recurse into the side that contains the Kth index. This reduces the average time complexity from O(N log N) to O(N)."
optimized: "O(N) Average"
bruteforce: "O(N log N)"
space: "O(1)"
date: "2025-11-21"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - selection
  - partitioning
  - divide-and-conquer
---

# Kth Largest Element (Quickselect)

**Platform:** LeetCode | **Difficulty:** Medium | **Pattern:** Quickselect

---

## Problem Description

Given an integer array `nums` and an integer `k`, return the `k`th largest element in the array. Note that it is the `k`th largest element in the sorted order, not the `k`th distinct element.

## Approaches

### 1. Quickselect Algorithm (Optimal Average) - $O(N)$ ⭐

**Idea:** Quickselect uses the same partition step as Quick Sort.

1. Pick a pivot and partition the array such that elements greater than the pivot are to its left and smaller are to its right.
2. Compare the pivot's index with `k-1`.
3. If the index matches, the pivot is the answer.
4. If the index is greater than `k-1`, search the left side; otherwise, search the right side.

### 2. Sorting (Brute Force) - $O(N \log N)$

**Idea:** Sort the entire array in descending order and return the element at index `k-1`.

---
