---
dayNumber: 21
title: "Heap Sort (Implementation)"
platform: "Custom"
link: "https://leetcode.com/problems/sort-an-array/"
difficulty: "Medium"
pattern: "Priority Queue / Heapify"
approach: "Build a Max-Heap from the input data. Repeatedly swap the root (maximum element) with the last element of the heap, reduce the heap size, and heapify the new root."
optimized: "O(N log N)"
bruteforce: "O(N log N)"
space: "O(1)"
date: "2025-11-18"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - sorting
  - heap
  - in-place
---

# Heap Sort (Implementation)

**Platform:** Custom | **Difficulty:** Medium | **Pattern:** Priority Queue

---

## Problem Description

Given an array of integers, sort the array using the **Heap Sort** algorithm. This algorithm is an in-place comparison-based sort that uses a Binary Heap data structure.

## Approaches

### 1. Max-Heap Implementation (Optimal) - $O(N \log N)$ ⭐

**Idea:** This algorithm consists of two main phases:

1.  **Build Max-Heap:** Transform the input array into a Max-Heap in $O(N)$ time.
2.  **Sort:** Repeatedly extract the maximum element (the root) and place it at the end of the array. After each extraction, use the `heapify` function to maintain the heap property in $O(\log N)$ time.

**Key Advantages:**

- **In-place:** Requires only $O(1)$ auxiliary space.
- **Guaranteed Performance:** Unlike Quick Sort, it has a guaranteed $O(N \log N)$ worst-case time complexity.

---
