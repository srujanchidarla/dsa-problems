---
dayNumber: 7
title: "Half Diamond Pattern"
platform: "Custom"
link: "[LINK TO BE ADDED]"
difficulty: "Easy"
pattern: "Symmetry Combination"
approach: "Print the pattern in two halves: the increasing part (top) and the decreasing part (bottom)."
optimized: "O(N²)"
bruteforce: "O(N²)"
space: "O(1)"
date: "2025-10-24"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - patterns
  - symmetry
---

# Half Diamond Pattern

**Platform:** Custom | **Difficulty:** Easy | **Pattern:** Symmetry Combination

---

## Problem Description

The task is to print a pattern shaped like a half-diamond, given a size $N$. The pattern increases from 1 to $N$ characters and then decreases back to 1.

---

## Example (N=5)

---

## Approaches

### 1. Two-Loop Approach (Optimal) - $O(N^2)$ ⭐

**Idea:** The cleanest way is to use two separate sets of nested loops, one for each half.

1.  **Increasing Half:** Loop $i$ from $1$ to $N$. Print $i$ characters.
2.  **Decreasing Half:** Loop $i$ from $N-1$ down to $1$. Print $i$ characters.

### 2. Single-Loop Approach (Advanced Indexing) - $O(N^2)$

**Idea:** Use a single loop that runs for $2N-1$ rows, and calculate the number of characters to print based on the row index relative to $N$.

---
