---
dayNumber: 3
title: "The Missing Number"
platform: "Custom"
link: "[LINK TO BE ADDED]"
difficulty: "Easy"
pattern: "Summation/XOR Logic"
approach: "Use the arithmetic series formula (N*(N+1)/2) to find the expected sum, and subtract the actual sum of the array elements to find the missing number."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-10-25"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - array
  - math
  - clever-approach
---

# The Missing Number

**Platform:** Custom | **Difficulty:** Easy | **Pattern:** Summation/XOR Logic

---

## Problem Description

Given an array containing $N$ distinct numbers taken from the range $0$ to $N$, find the single number that is missing from the array.

---

## Approaches

### 1. Summation Method (Optimal) - $O(N)$ ⭐

**Idea:** Exploit the property of the arithmetic series sum. This is the most straightforward $O(N)$ method with $O(1)$ extra space.

1.  Calculate the **expected sum** of all numbers from $0$ to $N$ using the formula: $E = \frac{N(N+1)}{2}$. (Where $N$ is the size of the _full_ range, or `len(array)`).
2.  Calculate the **actual sum** ($A$) by iterating through the given array.
3.  The missing number is $E - A$.

### 2. XOR Method (Alternative Optimal) - $O(N)$

**Idea:** Use the property that $A \oplus A = 0$ and $A \oplus 0 = A$.

1.  Initialize `missing = N` (or $0$).
2.  Iterate from $i = 0$ to $N-1$ and perform: `missing = missing ^ i ^ array[i]`.
3.  The final value of `missing` will be the missing number.

---
