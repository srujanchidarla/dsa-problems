---
dayNumber: 15
title: "Sum of Digits (Recursive)"
platform: "HackerRank"
link: "https://www.hackerrank.com/challenges/sum-of-digits-of-a-number/problem"
difficulty: "Easy"
pattern: "Tail Recursion / Modulo"
approach: "Define the sum of digits of N as (N % 10) + sum_of_digits(N / 10). The base case is when N equals 0."
optimized: "O(log N)"
bruteforce: "O(log N)"
space: "O(log N)"
date: "2025-11-12"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - recursion
  - math
  - tail-recursion
---

# Sum of Digits (Recursive)

**Platform:** HackerRank | **Difficulty:** Easy | **Pattern:** Tail Recursion

---

## Problem Description

Given a non-negative integer $N$, calculate the sum of its digits using a recursive function.

## Approaches

### 1. Tail Recursion (Optimal) - $O(\log_{10} N)$ ⭐

**Idea:** The time complexity is logarithmic since the number of recursive calls is equal to the number of digits.

$$
\text{Sum}(N) = (N \pmod{10}) + \text{Sum}(\lfloor N / 10 \rfloor)
$$

The base case is $\text{Sum}(0) = 0$.

### 2. Brute Force (Iterative) - $O(\log_{10} N)$

**Idea:** Use a `while` loop with standard modulo/division until $N=0$. While iterative is usually preferred for stack efficiency, the complexity remains $\text{O}(\log N)$.

---
