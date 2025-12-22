---
dayNumber: 23
title: "Search in Rotated Sorted Array"
platform: "LeetCode"
link: "https://leetcode.com/problems/search-in-rotated-sorted-array/"
difficulty: "Medium"
pattern: "Modified Binary Search"
approach: "In a rotated sorted array, at least one half of the array (divided by the middle) is always sorted. We identify the sorted half and check if the target lies within its range to decide where to move our pointers."
optimized: "O(log N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-11-20"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - searching
  - binary-search
  - arrays
---

# Search in Rotated Sorted Array

**Platform:** LeetCode | **Difficulty:** Medium | **Pattern:** Modified Binary Search

---

## Problem Description

There is an integer array `nums` sorted in ascending order (with distinct values). Prior to being passed to your function, `nums` is possibly rotated at an unknown pivot index. Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or -1 if it is not in `nums`.

You must write an algorithm with $O(\log n)$ runtime complexity.

## Approaches

### 1. Modified Binary Search (Optimal) - $O(\log N)$ ⭐

**Idea:** 1. Calculate `mid`. 2. Determine which side is sorted:

- If `nums[left] <= nums[mid]`, the left side is sorted.
- Otherwise, the right side is sorted.

3. Check if the target is within the range of the sorted side:
   - If it is, adjust the pointers to search that side.
   - If not, the target must be in the other (unsorted/rotated) side.

### 2. Brute Force (Linear Scan) - $O(N)$

**Idea:** Iterate through the array once to find the target. While simple, it fails to meet the $O(\log N)$ requirement.

---
