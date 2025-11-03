---
dayNumber: 5
title: "Natural Numbers Sum"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/natural-numbers-sum"
difficulty: "Easy"
pattern: "Arithmetic Series Formula"
approach: "Use Gauss's formula, $S = \frac{N(N+1)}{2}$, to calculate the sum in constant time."
optimized: "O(1)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-10-27"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - math
  - formula
---

# Natural Numbers Sum

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Arithmetic Series

---

## Problem Description

Given a positive integer $N$, calculate the sum of all natural numbers from 1 to $N$.

## Approaches

### 1. Arithmetic Series Formula (Optimal) - $O(1)$ ⭐

**Idea:** This is the classic Gauss's problem. The sum of the first $N$ natural numbers is given by the formula:

$$
S = \frac{N(N+1)}{2}
$$

**Time:** $O(1)$
**Space:** $O(1)$

### 2. Brute Force Iteration - $O(N)$

**Idea:** Initialize a sum to zero and loop from 1 up to $N$, adding each number. This is computationally much slower than the formula for large $N$.

---
