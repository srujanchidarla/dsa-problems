---
dayNumber: 12
title: "Ternary Array Cost"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/ternary-array"
difficulty: "Medium"
pattern: "Local Cost Minimization / Greedy"
approach: "For each element A[i], calculate the conversion cost |A[i] - B[i]| for B[i] = 0, 1, and 2 (where B[i] != A[i]). Choose the B[i] that yields the minimum cost locally."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-11-09"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - array
  - greedy
  - minimization
---

# Ternary Array Cost

**Platform:** Smart Interviews | **Difficulty:** Medium | **Pattern:** Local Cost Minimization

---

## Problem Description

Given an array $A$ (elements can be anything), convert it to a ternary array $B$ (elements must be 0, 1, or 2). The cost is $\sum |A[i] - B[i]|$. Crucially, the constraint is that **$A[i] \neq B[i]$**. Find the minimum total conversion cost.

## Approaches

### 1. Greedy Local Minimum (Optimal) - $O(N)$ ⭐

**Idea:** Since the choice made for $A[i]$ does not affect the cost calculation for any other element $A[j]$, the total minimum cost is the sum of the minimum cost at _each_ index. This is a purely **greedy local minimization** problem.

For each $A[i]$, we test the three possible target values (0, 1, 2) and select the one that minimizes the cost $|A[i] - B[i]|$, subject to $A[i] \neq B[i]$.

**Time:** $O(N)$ (Three constant-time checks per element).
**Space:** $O(1)$ (Storing a single total sum).

---
