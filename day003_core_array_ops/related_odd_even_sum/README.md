---
dayNumber: 3
title: "Odd and Even Sum"
platform: "Custom"
link: "[LINK TO BE ADDED]"
difficulty: "Easy"
pattern: "Conditional Summation"
approach: "Use a single linear pass to check each element's parity and accumulate separate sums for odd and even numbers."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-10-25"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - array
  - traversal
  - conditional-logic
---

# Odd and Even Sum

**Platform:** Custom | **Difficulty:** Easy | **Pattern:** Conditional Summation

---

## Problem Description

Given an array of integers, calculate and return two separate values: the sum of all **even** numbers and the sum of all **odd** numbers.

---

## Approaches

### 1. Single Linear Pass (Optimal) - $O(N)$ ⭐

**Idea:** Process all elements in a single $O(N)$ loop. Use the modulo operator (`% 2`) to determine the parity (even or odd) of each number and add it to the corresponding accumulator.

1.  Initialize two variables: `even_sum = 0` and `odd_sum = 0`.
2.  Iterate through the array from start to end.
3.  Inside the loop, use the condition `if element % 2 == 0` to check for even numbers.
4.  If even, add to `even_sum`; otherwise, add to `odd_sum`.
5.  Return both sums.

**Time:** $O(N)$
**Space:** $O(1)$

---
