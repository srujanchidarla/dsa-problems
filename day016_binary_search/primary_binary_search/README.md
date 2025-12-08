---
dayNumber: 16
title: "Binary Search (Iterative & Recursive)"
platform: "LeetCode"
link: "https://leetcode.com/problems/binary-search/"
difficulty: "Easy"
pattern: "Logarithmic Search"
approach: "Compare the target to the middle element. If not equal, eliminate the half of the list where the target cannot lie and continue the search on the remaining half."
optimized: "O(log N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-11-13"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - searching
  - logarithmic
  - divide-and-conquer
---

# Binary Search (Iterative & Recursive)

**Platform:** LeetCode | **Difficulty:** Easy | **Pattern:** Logarithmic Search

---

## Problem Description

Given a **sorted array** of integers `nums` and an integer `target`, write a function to search for `target` in `nums`. If the target exists, return its index; otherwise, return -1.

## Approaches

### 1. Iterative Approach (Optimal) - $O(\log N)$ ⭐

**Idea:** Use two pointers, `left` and `right`, to define the current search space. Calculate the `mid` index. Based on the comparison of `nums[mid]` and `target`, adjust either `left` or `right` to cut the search space in half.

### 2. Recursive Approach (Alternative Optimal) - $O(\log N)$

**Idea:** The function calls itself on the left or right sub-array. While elegant, it uses $\text{O}(\log N)$ stack space.

### 3. Brute Force (Linear Scan) - $O(N)$

**Idea:** Iterate through the entire array from start to finish, checking each element against the target. This ignores the sorted property of the array.

---
