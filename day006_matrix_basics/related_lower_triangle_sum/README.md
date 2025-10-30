---
dayNumber: 6
title: "Lower Triangle Sum"
platform: "Smart Interviews"
link: "[LINK TO BE ADDED]"
difficulty: "Easy"
pattern: "Index-based Traversal / Conditionals"
approach: "Iterate through the matrix and only sum elements where the row index (i) is greater than or equal to the column index (j), i.e., i >= j."
optimized: "O(N²)"
bruteforce: "O(N²)"
space: "O(N²)"
date: "2025-10-23"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - matrix
  - index-logic
---

# Lower Triangle Sum

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Index Condition

---

## Problem Description

Given a square matrix of size $N \times N$, find the sum of its **lower triangle elements**. The lower triangle includes the main diagonal and all elements below it.

**Index Condition:** Elements $ar[i][j]$ are in the lower triangle if and only if **$i \ge j$**.

---

## Example

**Input:**
3 5 9 -2 -3 4 1 2 6 1

**Output:**
15

**Explanation:** Sum of elements (5, -3, 4, 2, 6, 1) = 15.

---

## Approaches

### 1. Simple Index Traversal (Optimal) - $O(N^2)$ ⭐

**Idea:** Since every cell must be checked, the time complexity is fixed at $O(N^2)$. The approach involves reading the matrix and applying the index condition during traversal.

1.  Read and store the entire $N \times N$ matrix.
2.  Use nested loops (row $i$, column $j$) to traverse the matrix.
3.  Add $ar[i][j]$ to the total sum **only if** the condition $i \ge j$ is met.

**Time:** $O(N^2)$ (Reading + Traversal)
**Space:** $O(N^2)$ (To store the matrix).

---
