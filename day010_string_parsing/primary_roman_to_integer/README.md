---
dayNumber: 10
title: "Roman to Integer"
platform: "LeetCode"
link: "https://leetcode.com/problems/roman-to-integer/"
difficulty: "Easy"
pattern: "Conditional Traversal / Hash Map Lookup"
approach: "Iterate through the string from left to right. If the current symbol's value is less than the next symbol's value, subtract it; otherwise, add it."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-11-07"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - string
  - hash-map
  - traversal
---

# Roman to Integer

**Platform:** LeetCode | **Difficulty:** Easy | **Pattern:** Conditional Lookup

---

## Problem Description

Given a Roman numeral represented by the characters I, V, X, L, C, D, and M, convert it to an integer. The complexity lies in handling the **subtraction rule** where a smaller value precedes a larger one (e.g., IV = 4, CM = 900).

## Approaches

### 1. Left-to-Right Conditional Traversal (Optimal) - $O(N)$ ⭐

**Idea:** Process the string in a single pass. The crucial logic is to look ahead:

1.  Use a **Hash Map** to store the integer value for each Roman symbol (I=1, V=5, etc.).
2.  Iterate from $i=0$ up to $N-2$.
3.  If $\text{Value}(S[i]) < \text{Value}(S[i+1])$, **subtract** $\text{Value}(S[i])$ from the total.
4.  Otherwise, **add** $\text{Value}(S[i])$ to the total.
5.  Always **add** the value of the final character $S[N-1]$.

### 2. Right-to-Left Traversal (Alternative Optimal) - $O(N)$

**Idea:** This is often considered cleaner. Start the iteration from the rightmost character.

1. Initialize the total with the value of the last character.
2. Iterate backward ($i=N-2$ down to 0).
3. If $\text{Value}(S[i]) < \text{Value}(S[i+1])$, **subtract** $\text{Value}(S[i])$ (subtraction case).
4. Otherwise, **add** $\text{Value}(S[i])$ (addition case).

**Time:** $O(N)$
**Space:** $O(1)$ (The Hash Map size is constant, 7 entries).

---
