---
dayNumber: 7
title: "Triangle and Pyramid Patterns"
platform: "Custom"
link: "[LINK TO BE ADDED]"
difficulty: "Easy"
pattern: "Row-Index Dependent Printing"
approach: "Use the row index (i) to determine the number of characters or spaces to print in the inner loop."
optimized: "O(N²)"
bruteforce: "O(N²)"
space: "O(1)"
date: "2025-10-24"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - patterns
  - loops
  - symmetry
---

# Triangle and Pyramid Patterns

**Platform:** Custom | **Difficulty:** Easy | **Pattern:** Index Logic

---

## Problem Description

The task is to print two patterns based on a single size input $N$:

1.  **Triangle Pattern (Right-Angled):** A right-angled triangle where the number of characters in a row $i$ is determined by $i$.
2.  **Pyramid Pattern (Isosceles/Centered):** A centered triangle that uses spaces before the characters to achieve symmetry.

---

## Examples (N=5)

### 1. Triangle Pattern

**Logic:** Print `i` characters in row $i$.

### 2. Pyramid Pattern

**Logic:** Print `N-i-1` spaces, then `2*i + 1` characters in row $i$.

---

## Approaches

### 1. Triangle Pattern (Optimal) - $O(N^2)$ ⭐

**Idea:** The complexity is always $O(N^2)$ as it sums all numbers from 1 to N.
**Loop Logic:** The inner loop runs from $j=1$ up to the current row number.

### 2. Pyramid Pattern (Optimal) - $O(N^2)$

**Idea:** Requires two distinct inner loops per row:

1.  **Space Loop:** Print leading spaces (`N - i - 1`).
2.  **Character Loop:** Print the characters (`2 * i + 1`).

---
