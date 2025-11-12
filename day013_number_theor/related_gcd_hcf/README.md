---
dayNumber: 13
title: "Greatest Common Divisor (GCD/HCF)"
platform: "TakeUForward"
link: "https://takeuforward.org/plus/dsa/problems/gcd-of-two-numbers"
difficulty: "Easy"
pattern: "Euclidean Algorithm"
approach: "Use the efficient Euclidean Algorithm, which relies on the property: GCD(a, b) = GCD(b, a % b)."
optimized: "O(log(min(A,B)))"
bruteforce: "O(min(A,B))"
space: "O(1)"
date: "2025-11-10"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - math
  - recursion
  - euclidean-algo
---

# Greatest Common Divisor (GCD/HCF)

**Platform:** TakeUForward | **Difficulty:** Easy | **Pattern:** Euclidean Algorithm

---

## Problem Description

Given two positive integers $A$ and $B$, find their greatest common divisor (GCD), also known as the highest common factor (HCF).

## Approaches

### 1. Euclidean Algorithm (Optimal) - $O(\log(\min(A, B)))$ ⭐

**Idea:** This is the most efficient known algorithm for GCD. It is based on the recursive property: $\text{GCD}(A, B) = \text{GCD}(B, A \pmod B)$.

### 2. Brute Force - $O(\min(A, B))$

**Idea:** Iterate from $\min(A, B)$ down to 1 and check divisibility. This is slow for large inputs.

---
