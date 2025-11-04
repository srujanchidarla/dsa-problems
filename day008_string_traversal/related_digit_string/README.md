---
dayNumber: 8
title: "Digit String Check"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/digit-string"
difficulty: "Easy"
pattern: "Character Type Check"
approach: "Iterate through the string and use a built-in character method (e.g., isdigit() or Character.isDigit()) to check if every character is a numerical digit."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-10-30"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - string
  - character-check
---

# Digit String Check

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Character Type

---

## Problem Description

Given a string $S$, determine if the string consists entirely of numerical digits (0-9).

## Approaches

### 1. Single Pass Character Check (Optimal) - $O(N)$ ⭐

**Idea:** Iterate through the string, and if at any point a non-digit character is found, the check immediately fails and returns `false`.

**Time:** $O(N)$ (Worst case: string is all digits)
**Space:** $O(1)$

---
