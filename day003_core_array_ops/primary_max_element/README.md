---
dayNumber: 3
title: "Max Element in Array"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/max-element-in-array"
difficulty: "Easy"
pattern: "Linear Traversal / Simple Scan"
approach: "Initialize a variable to the smallest possible value and iterate through the array, updating the maximum value encountered."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-10-25"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - array
  - traversal
  - simple-scan
---

# Max Element in Array

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Linear Scan

---

## Problem Description

Given an array of integers, find and return the largest element within the array.

---

## Approaches

### 1. Linear Scan (Optimal) - $O(N)$ ⭐

**Idea:** Since every element must be checked at least once, the optimal time complexity is $O(N)$.

1.  Initialize a variable, `max_val`, with the value of the first element in the array.
2.  Iterate through the array from the second element to the end, updating `max_val` if the current element is larger.

**Time:** $O(N)$
**Space:** $O(1)$

---
