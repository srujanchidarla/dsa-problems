---
dayNumber: 15
title: "N-th Fibonacci Number"
platform: "LeetCode"
link: "https://leetcode.com/problems/fibonacci-number/"
difficulty: "Medium"
pattern: "Overlapping Subproblems / Memoization"
approach: "Define $F(N) = F(N-1) + F(N-2)$. The base cases are $F(0)=0$ and $F(1)=1$. Use memoization to turn the inefficient exponential complexity into linear time."
optimized: "O(N)"
bruteforce: "O(2ⁿ)"
space: "O(N)"
date: "2025-11-12"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - recursion
  - dynamic-programming
  - memoization
---

# N-th Fibonacci Number

**Platform:** LeetCode | **Difficulty:** Medium | **Pattern:** Memoization

---

## Problem Description

Given an integer $N$, calculate the $N$-th Fibonacci number.

## Approaches

### 1. Memoization/DP (Optimal) - $O(N)$ ⭐

**Idea:** Pure recursion leads to re-calculating the same subproblems repeatedly, resulting in $O(2^N)$ time complexity. Memoization (caching results) reduces this to $O(N)$.

1.  Use a global array or Hash Map (memo table) initialized to -1.
2.  In $F(N)$, check if the result is in the memo table. If yes, return it ($\text{O}(1)$).
3.  Otherwise, calculate $F(N-1) + F(N-2)$, store the result in the memo table, and return it.

### 2. Brute Force (Pure Recursion) - $O(2^N)$

**Idea:** Direct implementation of the recursive definition without caching. This is exponential and will time out for large $N$.

---
