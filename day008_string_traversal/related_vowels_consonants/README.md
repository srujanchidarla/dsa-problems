---
dayNumber: 8
title: "Vowels and Consonants"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/vowels-and-consonants"
difficulty: "Easy"
pattern: "Character Set Check"
approach: "Use a predefined set (HashSet in Java/C++, set in Python) of vowels for fast O(1) lookups during a single string traversal."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-10-30"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - string
  - set-check
---

# Vowels and Consonants

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Character Set Check

---

## Problem Description

Given a string $S$, count and report the total number of vowels and the total number of consonants.

## Approaches

### 1. Hash Set Lookup (Optimal) - $O(N)$ ⭐

**Idea:** Create a small, constant-size Hash Set containing all vowel characters. Iterate through the string once, checking if each character is present in the set ($O(1)$ lookup time).

**Time:** $O(N)$
**Space:** $O(1)$ (Set size is constant).

---
