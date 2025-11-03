---
dayNumber: 5
title: "Triangle Validator"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/triangle-validator"
difficulty: "Easy"
pattern: "Geometry / Inequality Rule"
approach: "Check the triangle inequality theorem: the sum of the lengths of any two sides of a triangle must be greater than the length of the third side."
optimized: "O(1)"
bruteforce: "O(1)"
space: "O(1)"
date: "2025-10-27"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - math
  - geometry
  - logic
---

# Triangle Validator

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Geometry Rule

---

## Problem Description

Given the lengths of three sides of a potential triangle, determine if a valid triangle can be formed from these lengths.

## Approaches

### 1. Triangle Inequality Check (Optimal) - $O(1)$ ⭐

**Idea:** A triangle is valid if and only if the **Triangle Inequality Theorem** holds true: the sum of the lengths of any two sides must be strictly greater than the length of the third side. This requires only three comparisons.

1.  Check: $a + b > c$
2.  Check: $a + c > b$
3.  Check: $b + c > a$

If all three conditions are true, return TRUE. Otherwise, return FALSE.

**Time:** $O(1)$
**Space:** $O(1)$

---
