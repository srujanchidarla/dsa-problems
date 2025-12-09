---
dayNumber: 17
title: "Bubble Sort"
platform: "Custom"
link: "http://example.com/custom-bubble-sort"
difficulty: "Easy"
pattern: "Quadratic Sorting / Swapping"
approach: "Repeatedly step through the list, compare adjacent elements, and swap them if they are in the wrong order. This process is repeated until the list is sorted."
optimized: "O(N²)"
bruteforce: "O(N²)"
space: "O(1)"
date: "2025-11-14"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - sorting
  - quadratic
  - in-place
---

# Bubble Sort

**Platform:** Custom | **Difficulty:** Easy | **Pattern:** Quadratic Sorting

---

## Problem Description

Given an array of integers, sort the array using the **Bubble Sort** algorithm. The algorithm works by repeatedly swapping adjacent elements if they are in the wrong order.

## Approaches

### 1. Standard Bubble Sort (Optimal) - $O(N^2)$ ⭐

**Idea:** Use nested loops. The outer loop runs $N$ times (for each pass). The inner loop iterates through the unsorted portion of the array, performing swaps. After each outer pass, the largest unsorted element "bubbles up" to its correct position at the end.

### 2. Optimized Bubble Sort (Best Case $O(N)$)

**Idea:** Add a **flag** to the inner loop. If no swaps occur during an entire inner pass, the array is already sorted, and we can break the outer loop early.

### 3. Brute Force Sorting - $O(N^2)$

**Idea:** Use the standard implementation, but remove the optimization to check for already sorted status.

---
