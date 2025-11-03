---
dayNumber: 5
title: "Arithmetic Progression Check"
platform: "Smart Interviews"
link: "[LINK TO BE ADDED]"
difficulty: "Easy"
pattern: "Sequence Check / Difference"
approach: "Calculate the difference between the first two elements. Then, iterate through the rest of the array, checking if the difference between all consecutive pairs is constant."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-10-27"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - math
  - array
  - sequence
---

# Arithmetic Progression Check

**Platform:** Custom | **Difficulty:** Easy | **Pattern:** Sequence Check

---

## Problem Description

Given an array of numbers, determine if the numbers form an **Arithmetic Progression (AP)**. An AP is a sequence where the difference between the consecutive terms is constant.

## Approaches

### 1. Constant Difference Check (Optimal) - $O(N)$ ⭐

**Idea:** A sequence is an AP if and only if the difference between every adjacent pair of numbers is the same.

1.  If the array size is 0, 1, or 2, return TRUE (trivial AP).
2.  Calculate the initial common difference: $D = \text{array}[1] - \text{array}[0]$.
3.  Iterate through the array starting from the second element ($i=2$).
4.  In each step, check if $\text{array}[i] - \text{array}[i-1]$ equals $D$. If it ever doesn't match, return FALSE.
5.  If the loop finishes, return TRUE.

**Time:** $O(N)$
**Space:** $O(1)$

---
