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

1.  **Row Sum:** Print the sum of elements for each row. **Constraint:** Solve this without declaring or storing the full $N \times M$ matrix.
2.  **Column Sum:** Print the sum of elements for each column.

---

## Approaches

### 1. Matrix Row Sum (Streaming Approach) - O(N\*M), O(1) Extra Space

**Idea:** To meet the "without storing the matrix" constraint, we must calculate the row sum as we receive the input for that row.

1.  Read $N$ and $M$.
2.  Loop $N$ times (once per row).
3.  Inside the loop, initialize `row_sum = 0`.
4.  Loop $M$ times (once per column), reading each element and adding it to `row_sum`.
5.  After the inner loop finishes, print `row_sum`.

### 2. Matrix Column Sum (1D Array Simulation) - O(N\*M), O(M) Extra Space ⭐

**Idea:** To calculate column sums without storing the whole matrix, we need to store **only the column sums**.

1.  Read $N$ and $M$.
2.  Initialize an array (or vector) called `col_sums` of size $M$ to all zeros. **This is $O(M)$ space.**
3.  Loop $N$ times (rows).
4.  Inside the loop, loop $M$ times (columns).
5.  Read the current element $ar[i][j]$.
6.  Add this element to the corresponding column sum: `col_sums[j] += ar[i][j]`.
7.  After reading all $N \times M$ elements, print the elements of the `col_sums` array.

---

## Complexity Analysis

| Calculation           | Time    | Space | Notes                                                            |
| :-------------------- | :------ | :---- | :--------------------------------------------------------------- |
| Row Sum (Streaming)   | O(N\*M) | O(1)  | Reading all $N \times M$ elements once, constant extra space.    |
| Column Sum (1D Array) | O(N\*M) | O(M)  | Reading all $N \times M$ elements once, storing $M$ column sums. |

---

## Solutions

The provided solutions will demonstrate both calculations using a single pass over the input stream.

- 🐍 [solution.py](./solution.py)
- ☕ [solution.java](./solution.java)
- ⚡ [solution.cpp](./solution.cpp)
