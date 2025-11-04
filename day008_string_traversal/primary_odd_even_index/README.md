---
dayNumber: 8
title: "Odd Even Index"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/odd-even-index"
difficulty: "Easy"
pattern: "Index-based Conditional Traversal"
approach: "Iterate through the string index and check the parity (i % 2) of the index to route the character to the odd or even result string."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(N)"
date: "2025-10-30"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - string
  - index-logic
---

# Odd Even Index

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Index Logic

---

## Problem Description

Given a string $S$, separate the characters into two new strings: one containing characters from **even indices** ($0, 2, 4, \dots$) and one containing characters from **odd indices** ($1, 3, 5, \dots$).

## Approaches

### 1. Single Linear Pass (Optimal) - $O(N)$ ⭐

**Idea:** A single loop is required to process every character, which is the optimal time complexity.

1. Initialize two empty strings/builders: `even_chars` and `odd_chars`.
2. Iterate from $i=0$ to $N-1$.
3. Check the parity of the index $i$: if $i \pmod 2 = 0$, append the character to `even_chars`; otherwise, append to `odd_chars`.

**Time:** $O(N)$
**Space:** $O(N)$ (to store the two result strings)

---
