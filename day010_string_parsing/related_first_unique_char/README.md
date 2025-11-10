---
dayNumber: 10
title: "First Unique Character in a String"
platform: "LeetCode"
link: "https://leetcode.com/problems/first-unique-character-in-a-string/"
difficulty: "Easy"
pattern: "Two-Pass Hashing / Frequency Count"
approach: "Use a two-pass approach: 1) Count frequencies in a Hash Map. 2) Iterate through the string again and return the index of the first character with a count of 1."
optimized: "O(N)"
bruteforce: "O(N²)"
space: "O(1)"
date: "2025-11-07"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - string
  - hash-map
  - frequency
---

# First Unique Character in a String

**Platform:** LeetCode | **Difficulty:** Easy | **Pattern:** Two-Pass Hashing

---

## Problem Description

Given a string $S$, find the first non-repeating character in it and return its index. If it does not exist, return -1.

## Approaches

### 1. Two-Pass Hashing (Optimal) - $O(N)$ ⭐

**Idea:** This is the optimal time complexity solution. You need two passes: the first to gather all frequency data, and the second to check the original indices. Since the character set (a-z) is small and constant, the space complexity is considered $O(1)$.

1.  **Pass 1 (Count):** Use a fixed-size array (or Hash Map) of size 26 to store the frequency of every character. $\text{O}(N)$.
2.  **Pass 2 (Find):** Iterate through the original string _again_. The first character you encounter whose count is exactly 1 is the answer. Return its index. $\text{O}(N)$.

### 2. Brute Force - $O(N^2)$

**Idea:** For every character $S[i]$, iterate through the entire rest of the string ($S[j]$ where $j \ne i$) to see if $S[i]$ is repeated.

**Time:** $\text{O}(N^2)$.

---
