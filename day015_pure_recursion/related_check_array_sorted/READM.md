---
dayNumber: 15
title: "Check if Array is Sorted"
platform: "GFG"
link: "https://www.geeksforgeeks.org/program-check-array-sorted-using-recursion/"
difficulty: "Easy"
pattern: "Array Subdivision / Boolean Recursion"
approach: "Define the problem as: the array is sorted if (a[0] <= a[1]) AND the rest of the array (starting from index 1) is also sorted. The base case is a single-element array."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(N)"
date: "2025-11-12"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - recursion
  - array
  - traversal
---

# Check if Array is Sorted (Recursive)

**Platform:** GFG | **Difficulty:** Easy | **Pattern:** Array Subdivision

---

## Problem Description

Given an array of integers, determine if the array is sorted in non-decreasing order using only recursion.

## Approaches

### 1. Array Subdivision (Optimal) - $O(N)$ ⭐

**Idea:** The complexity is fixed at $O(N)$ as every pair of elements must be compared. Recursion is used to structure the traversal.

1.  Define a recursive function `isSorted(array, index)`.
2.  **Base Case:** If `index` is the last element, return TRUE.
3.  **Recursive Step:** Check if `array[index] <= array[index + 1]`. If this is true, return the result of `isSorted(array, index + 1)`. If it is false, immediately return FALSE.

### 2. Brute Force (Iterative) - $O(N)$

**Idea:** Use a simple iterative loop from $i=0$ to $N-2$, checking the pair at each step. This is the non-recursive alternative.

---
