---
dayNumber: 5
title: "Factorial"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/factorial"
difficulty: "Easy"
pattern: "Iteration / Recursion"
approach: "Use an iterative loop starting from 1 up to N, multiplying the result at each step. Must handle data type overflow for large N."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-10-27"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - math
  - iteration
  - recursion
---

# Factorial

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Iteration/Recursion

---

## Problem Description

Given a non-negative integer $N$, calculate its factorial, denoted $N!$. $N!$ is the product of all positive integers less than or equal to $N$. ($0! = 1$).

## Approaches

### 1. Iterative Method (Optimal) - $O(N)$ ⭐

**Idea:** Iteration is generally preferred over recursion to avoid potential stack overflow issues and the overhead of function calls, while maintaining $O(N)$ time complexity.

1.  Initialize result variable to 1.
2.  Loop from $i=1$ up to $N$.
3.  In each step, multiply the result by $i$.
4.  **Critical Note:** Use a large enough data type (e.g., `long long` in C++, `long` in Java) to prevent integer overflow.

### 2. Recursive Method - $O(N)$

**Idea:** Define $N! = N \times (N-1)!$ with the base case $0! = 1$. This is elegant but may have performance/stack depth issues for very large $N$.

---
