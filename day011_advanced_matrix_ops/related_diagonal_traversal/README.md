---
dayNumber: 11
title: "Diagonal Traversal of Matrix"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-primary/problems/diagonal-traversal-of-matrix"
difficulty: "Medium"
pattern: "Index Grouping"
approach: "Elements on the same anti-diagonal share the same sum of indices (i + j). Group elements by this sum and process the groups."
optimized: "O(N²)"
bruteforce: "O(N²)"
space: "O(N²)"
date: "2025-11-08"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - matrix
  - traversal
  - index-logic
---

# Diagonal Traversal of Matrix

**Platform:** Smart Interviews | **Difficulty:** Medium | **Pattern:** Index Grouping

---

## Problem Description

Given a 2D matrix, traverse and print its elements diagonally (usually starting from the top-left, alternating direction for each diagonal).

## Approaches

### 1. Index Grouping with Hashing (Optimal) - $O(N^2)$ ⭐

**Idea:** The elements belonging to the same diagonal share a constant property: the sum of their indices ($i+j$).

1.  **Group:** Iterate through the matrix, calculating the sum $S = i + j$. Use a hash map (or array) where the key is $S$ and the value is a list of elements belonging to that diagonal.
2.  **Order:** Iterate through the map keys (sums) from 0 to $2N-2$, printing the elements of each list. Additional logic is needed if the problem requires the traversal to alternate direction (up-right vs. down-left).

**Time:** $O(N^2)$ (Reading and grouping)
**Space:** $O(N^2)$ (To store all grouped elements).

---
