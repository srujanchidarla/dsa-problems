---
dayNumber: 4
title: "Find Duplicate Number in Array"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/find-duplicate-number-in-array"
difficulty: "Medium"
pattern: "Cycle Detection (Floyd's Tortoise and Hare)"
approach: "Treat the array as a linked list where the index i points to the value nums[i]. A duplicate creates a cycle."
optimized: "O(N)"
bruteforce: "O(N²)"
space: "O(1)"
date: "2025-10-26"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - array
  - cycle-detection
  - two-pointers
---

# Find Duplicate Number in Array

**Platform:** Smart Interviews | **Difficulty:** Medium | **Pattern:** Cycle Detection

---

## Problem Description

Given an array `nums` containing $n + 1$ integers where each integer is between 1 and $n$ (inclusive). Assume there is only one duplicate number, find and return this duplicate. The solution must use $O(1)$ extra space and run in less than $O(n^2)$ time.

---

## Approaches

### 1. Floyd's Tortoise and Hare (Optimal) - $O(N)$ Time, $O(1)$ Space ⭐

**Idea:** Treat the array as a linked list where `index -> nums[index]`. A duplicate number creates a cycle.

1.  **Phase 1: Detect the cycle.** Use two pointers, `slow` (moves 1 step) and `fast` (moves 2 steps). They meet inside the cycle.
2.  **Phase 2: Find the entry point (duplicate).** Reset `slow` to index 0. Move both `slow` and `fast` one step at a time until they meet again. The meeting point is the duplicate number.

### 2. Brute Force Sorting - $O(N \log N)$

**Idea:** Sort the array and check for adjacent equal elements. Fails the $O(1)$ space requirement.

---
