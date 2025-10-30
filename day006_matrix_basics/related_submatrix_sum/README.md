---
dayNumber: 6
title: "Submatrix Sum"
platform: "Custom/Smart Interviews"
link: "[LINK TO BE ADDED]"
difficulty: "Medium"
pattern: "Range Query / 2D Prefix Sum (Optimized)"
approach: "Brute force sum for small N (O(N^2)) or 2D Prefix Sum for optimization (O(1) query)."
optimized: "O(N²)"
bruteforce: "O(N²)"
space: "O(N²)"
date: "2025-10-23"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - matrix
  - prefix-sum
---

# Submatrix Sum

**Platform:** Custom/Smart Interviews | **Difficulty:** Medium | **Pattern:** Range Query

---

## Problem Description

Given a matrix of size $N \times N$ and four integers $(i, j, k, l)$, calculate the sum of the sub-matrix from the top-left coordinate $(i, j)$ to the bottom-right coordinate $(k, l)$.

---

## Example

**Input:**
3 1 1 2 2 1 2 3 4 5 6 7 8 9

**Output:**
28

**Explanation:** Sum of elements (5, 6, 8, 9) = 28.

---

## Approaches

### 1. Brute Force Summation - $O(N^2)$ per Query (Worst Case)

**Idea:** Directly iterate over the specified submatrix boundaries. Loop from row $r=i$ to $k$ and column $c=j$ to $l$, adding each element.

**Time:** $O((k-i) \cdot (l-j))$, which is $O(N^2)$ in the worst case (querying the entire matrix).
**Space:** $O(N^2)$ (to store the matrix).

### 2. 2D Prefix Sum (Optimized) - $O(1)$ per Query ⭐

**Idea:** Pre-calculate the sum of all sub-matrices starting from $(0, 0)$ to any point $(r, c)$. This is stored in a $PrefixSum$ matrix.

The sum of the sub-matrix from $(i, j)$ to $(k, l)$ is then calculated in $O(1)$ using the **inclusion-exclusion principle**:

$$
\text{Sum}(i, j, k, l) = PS[k][l] - PS[i-1][l] - PS[k][j-1] + PS[i-1][j-1]
$$

**Time:** $O(N^2)$ for preprocessing; $O(1)$ per query.
**Space:** $O(N^2)$ (to store the prefix sum matrix).

---
