---
dayNumber: 10
title: "Integer to Roman"
platform: "LeetCode"
link: "https://leetcode.com/problems/integer-to-roman/"
difficulty: "Medium"
pattern: "Greedy Lookup / Paired Hash Map"
approach: "Use a lookup table of Roman values and symbols, sorted from largest to smallest. Greedily subtract the largest possible value until the integer reaches zero."
optimized: "O(1)"
bruteforce: "O(1)"
space: "O(1)"
date: "2025-11-07"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - string
  - hash-map
  - greedy
---

# Integer to Roman

**Platform:** LeetCode | **Difficulty:** Medium | **Pattern:** Greedy Lookup

---

## Problem Description

Given an integer $N$ (guaranteed to be between 1 and 3999), convert it to its corresponding Roman numeral string.

## Approaches

### 1. Greedy Lookup (Optimal) - $O(1)$ ⭐

**Idea:** Since the Roman system has a fixed number of unique symbols and subtraction pairs (13 total), the process is a **greedy algorithm**. We repeatedly find the largest Roman value less than or equal to the remaining number and subtract it.

**Time:** $\text{O}(1)$ (The number of operations is fixed, proportional to 13 lookups, not $N$).
**Space:** $\text{O}(1)$ (Fixed-size lookup table).

---
