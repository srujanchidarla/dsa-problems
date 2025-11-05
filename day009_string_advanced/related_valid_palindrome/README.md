---
dayNumber: 9
title: "Valid Palindrome (Alpha-Numeric Filter)"
platform: "LeetCode"
link: "https://leetcode.com/problems/valid-palindrome/"
difficulty: "Easy"
pattern: "Two Pointers / Filtering"
approach: "Use two pointers (one at start, one at end). Move pointers inward, skipping non-alphanumeric characters. Compare the characters after converting them to the same case."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-10-31"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - string
  - two-pointers
  - validation
---

# Valid Palindrome (Alpha-Numeric Filter)

**Platform:** LeetCode | **Difficulty:** Easy | **Pattern:** Two Pointers

---

## Problem Description

Given a string $S$, determine if it is a palindrome, considering only **alphanumeric characters** and ignoring case.

A palindrome is a word, phrase, or sequence that reads the same backwards as forwards.

## Approaches

### 1. Two-Pointer In-Place Check (Optimal) - $O(N)$ ⭐

**Idea:** Use two pointers that converge from the start and end of the string. The efficiency comes from performing the filtering and comparison simultaneously in a single pass without creating a new, filtered string.

1. Initialize `left` pointer to index 0 and `right` pointer to $N-1$.
2. Loop while `left < right`.
3. Inside the loop, advance the `left` pointer until it hits an alphanumeric character.
4. Advance the `right` pointer until it hits an alphanumeric character.
5. Compare the characters at `left` and `right` (after normalizing case). If they don't match, return FALSE.
6. Advance both `left` and `right` by one.

**Time:** $O(N)$ (Each character is checked at most twice)
**Space:** $O(1)$ (No auxiliary space proportional to $N$ is needed).

### 2. Brute Force (Preprocessing) - $O(N)$

**Idea:** Create a new string by filtering out all non-alphanumeric characters and converting everything to lowercase. Then, check if the new string is equal to its reverse. This uses $O(N)$ extra space.

---
