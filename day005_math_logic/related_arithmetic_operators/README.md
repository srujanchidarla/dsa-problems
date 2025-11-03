---
dayNumber: 5
title: "Arithmetic Operators"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/arithmetic-operators"
difficulty: "Easy"
pattern: "Conditional Logic / Switch"
approach: "Read two numbers and a character operator. Use conditional logic (if/else or switch) to perform the correct operation."
optimized: "O(1)"
bruteforce: "O(1)"
space: "O(1)"
date: "2025-10-27"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - math
  - logic
  - operator
---

# Arithmetic Operators

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Conditional Logic

---

## Problem Description

Given two integers, $A$ and $B$, and an arithmetic operator character (e.g., '+', '-', '\*', '/'), calculate and return the result of the operation $A \text{ op } B$.

## Approaches

### 1. Conditional Execution (Optimal) - $O(1)$ ⭐

**Idea:** The solution involves only input, a lookup/comparison, and a single arithmetic operation, making it $O(1)$.

1.  Read the two operands ($A$, $B$) and the operator ($op$).
2.  Use a `switch` statement (C++/Java) or `if/else if` ladder (Python) based on the operator character.
3.  Perform the corresponding operation. Include a check for division by zero if necessary.

**Time:** $O(1)$
**Space:** $O(1)$

---
