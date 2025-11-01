---
dayNumber: 7
title: "Filled and Hollow Rectangle"
platform: "Custom"
link: "[LINK TO BE ADDED]"
difficulty: "Easy"
pattern: "Basic Nested Loops"
approach: "Use two nested loops (i for rows, j for columns). For Hollow, add a conditional check for boundaries."
optimized: "O(N*M)"
bruteforce: "O(N*M)"
space: "O(1)"
date: "2025-10-24"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - patterns
  - loops
---

# Filled and Hollow Rectangle Patterns

**Platform:** Custom | **Difficulty:** Easy | **Pattern:** Nested Loops

---

## Problem Description

The task is to print two fundamental patterns using nested loops, given dimensions $N$ (rows) and $M$ (columns):

1.  **Filled Rectangle:** Print a solid block of characters (e.g., `*`).
2.  **Hollow Rectangle:** Print a character only on the boundary (first/last row/column).

---

## Examples

### 1. Filled Rectangle (N=3, M=5)

### 2. Hollow Rectangle (N=4, M=5)

---

## Approaches

### 1. Filled Rectangle (Optimal) - $O(N \cdot M)$ ⭐

**Idea:** The complexity is proportional to the area. Use one loop for rows ($i$) and one loop for columns ($j$).

### 2. Hollow Rectangle (Optimal) - $O(N \cdot M)$

**Idea:** Requires a conditional check inside the inner loop: print the character only if the current position is on the boundary.
The condition is: **`i == 0 || i == N-1 || j == 0 || j == M-1`**

---
