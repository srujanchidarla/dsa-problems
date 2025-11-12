---
dayNumber: 13
title: "Check for Prime and Print Divisors"
platform: "TakeUForward"
link: "https://takeuforward.org/plus/dsa/problems/check-for-prime-number (and Divisors of a Number)"
difficulty: "Medium"
pattern: "Optimized Factorization / Square Root Check"
approach: "To check for primality or find divisors, only iterate up to $\sqrt{N}$ because if $N=a \times b$, then one factor must be $\le \sqrt{N}$."
optimized: "O(sqrt(N))"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-11-10"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - math
  - prime
  - factorization
---

# Check for Prime and Print Divisors

**Platform:** TakeUForward | **Difficulty:** Medium | **Pattern:** Optimized Factorization

---

## Problem Description

The task is to perform two related factorization operations on a given integer $N$:

1.  **Check for Prime:** Determine if $N$ is a prime number.
2.  **Print All Divisors:** Find and print all integers that divide $N$.

## Approaches

### 1. Square Root Optimization (Optimal) - $O(\sqrt{N})$ ⭐

**Idea:** Any composite number $N$ must have at least one factor $\le \sqrt{N}$.

**Primality Check:** Iterate from $i=2$ to $\sqrt{N}$. If any $i$ divides $N$, it's not prime.

**Print Divisors:** When an index $i$ divides $N$, both $i$ and $N/i$ are divisors. This allows us to find all divisors in $\text{O}(\sqrt{N})$ time.

### 2. Brute Force - $O(N)$

**Idea:** Iterate from $i=2$ up to $N$ (for primality or divisors).

---
