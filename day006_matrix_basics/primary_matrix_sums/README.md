---
dayNumber: 6
title: Matrix Row and Column Sums
platform: Smart Interviews
link: https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/matrix-row-sum (and Column Sum)
difficulty: Easy
pattern: Streaming Input / 1D Array Simulation
approach: Calculate Row Sums by streaming and Column Sums using an auxiliary 1D array.
optimized: O(N*M)
bruteforce: O(N*M)
space: O(M)
date: 2025-10-23
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - matrix
  - array
  - streaming
---

# Matrix Row and Column Sums

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Streaming/Matrix Traversal

---

## Problem Description (Combined)

Given a matrix of size $N \times M$, the task is to perform two separate calculations:

1.  **Row Sum:** Print the sum of elements for each row. **Constraint:** Solve this without declaring or storing the full $N \times M$ matrix (i.e., streaming).
2.  **Column Sum:** Print the sum of elements for each column.

---

## Approaches

### 1.Matrix Row Sum (Streaming Approach) - O(N\*M), O(1) Extra Space ⭐

**Idea:** To meet the "without storing the matrix" constraint, we must calculate the row sum as we receive the input for that row. We read $M$ elements, calculate their sum, print it, and discard the row before reading the next. This approach showcases efficient memory management.

### 2.Matrix Column Sum (1D Array Simulation) - O(N\*M), O(M) Extra Space

**Idea:** Since column sums require data from _all_ rows to be complete, we must store the intermediate totals. We initialize a 1D array of size $M$ (`col_sums`). As we read each element $ar[i][j]$, we add it to `col_sums[j]`. This uses $O(M)$ extra space, but still allows for a single, efficient $O(N \cdot M)$ pass over the input.

---

## Complexity Analysis

| Calculation           | Time    | Space | Notes                                                            |
| :-------------------- | :------ | :---- | :--------------------------------------------------------------- |
| Row Sum (Streaming)   | O(N\*M) | O(1)  | Reading all $N \times M$ elements once, constant extra space.    |
| Column Sum (1D Array) | O(N\*M) | O(M)  | Reading all $N \times M$ elements once, storing $M$ column sums. |

---

## Solutions

The provided solutions demonstrate a combined approach, calculating both sums in a single efficient pass over the input stream.

- 🐍 [solution.py](./solution.py)
- ☕ [solution.java](./solution.java)
- ⚡ [solution.cpp](./solution.cpp)
