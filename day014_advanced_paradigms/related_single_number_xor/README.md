---
dayNumber: 14
title: "Single Number"
platform: "LeetCode"
link: "https://leetcode.com/problems/single-number/"
difficulty: "Easy"
pattern: "Bit-Manipulation (XOR)"
approach: "Utilize the XOR property A ^ A = 0 and A ^ 0 = A. XORing all elements in the array will cancel out all paired numbers, leaving only the unique single number."
optimized: "O(N)"
bruteforce: "O(N²)"
space: "O(1)"
date: "2025-11-11"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - bit-manipulation
  - xor
  - array
---

# Single Number

**Platform:** LeetCode | **Difficulty:** Easy | **Pattern:** XOR Application

---

## Problem Description

Given a non-empty array of integers, every element appears twice except for one. Find that single one. The solution must have linear runtime complexity and use only constant extra space.

## Approaches

### 1. XOR Property (Optimal) - $O(N)$ Time, $O(1)$ Space ⭐

**Idea:** The mathematical property of the XOR operator is perfect for this:

$$
A \oplus B \oplus A = (A \oplus A) \oplus B = 0 \oplus B = B
$$

By XORing every element in the array together, all pairs cancel out, leaving only the single, unpaired number.

### 2. Brute Force - $O(N^2)$

**Idea:** For every element, iterate through the rest of the array to check for a duplicate.

---
