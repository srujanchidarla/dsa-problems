---
dayNumber: 14
title: "Power of Two"
platform: "LeetCode"
link: "https://leetcode.com/problems/power-of-two/"
difficulty: "Easy"
pattern: "Bit-Manipulation (Masking)"
approach: "A positive integer N is a power of two if and only if N has exactly one bit set to 1. The bitwise trick N & (N - 1) clears the rightmost set bit."
optimized: "O(1)"
bruteforce: "O(log N)"
space: "O(1)"
date: "2025-11-11"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - bit-manipulation
  - masking
  - power-of-two
---

# Power of Two

**Platform:** LeetCode | **Difficulty:** Easy | **Pattern:** Bit Masking

---

## Problem Description

Given an integer $N$, return `true` if it is a power of two.

## Approaches

### 1. Bitwise Trick (Optimal) - $O(1)$ ⭐

**Idea:** A number $N$ is a power of two if and only if $N > 0$ and its binary representation has exactly one bit set (e.g., $8 = 1000_2$, $16 = 10000_2$).
The trick $\mathbf{N \& (N - 1)}$ clears the rightmost set bit. If $N$ has only one set bit, this operation results in 0.

### 2. Brute Force / Logarithm - $O(\log N)$

**Idea:** Repeatedly divide $N$ by 2 until it reaches 1. If at any step the remainder is not 0, it's not a power of two.

---
