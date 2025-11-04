---
dayNumber: 8
title: "Letter Coverage (Pangram Check)"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/letter-coverage"
difficulty: "Easy"
pattern: "Boolean Array / Frequency Hashing"
approach: "Use a fixed-size boolean array (size 26) to mark the presence of each letter (a-z) encountered during a single pass."
optimized: "O(N)"
bruteforce: "O(N²)"
space: "O(1)"
date: "2025-10-30"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - string
  - hashing
  - boolean-array
---

# Letter Coverage (Pangram Check)

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Boolean Array Hashing

---

## Problem Description

Given a string $S$, determine if it contains every letter of the alphabet (a-z) at least once. (This is often known as a Pangram check).

## Approaches

### 1. Boolean Array Hashing (Optimal) - $O(N)$ ⭐

**Idea:** Use a fixed-size boolean array of size 26 for $O(1)$ updates. Iterate through the string, set the corresponding index to `true`, and check if all 26 spots were marked.

**Time:** $O(N) + O(26) = O(N)$
**Space:** $O(1)$ (Array size is fixed at 26).

---
