---
dayNumber: 1
title: Duplicate Integer
platform: NeetCode 150
link: https://neetcode.io/problems/duplicate-integer
difficulty: Easy
pattern: Hash Table / Set
approach: Use a HashSet/Unordered Set to track seen numbers.
optimized: O(n)
bruteforce: O(n²)
space: O(n)
date: 2025-10-23
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - array
  - hash-table
---

# Duplicate Integer(Contains Duplicate)

**Platform:** NeetCode 150 | **Difficulty:** Easy | **Pattern:** Hash Table

---

## Problem Description

Given an integer array `nums`, return **true** if any value appears **more than once** in the array, otherwise return **false**.

---

## Examples

**Example 1:**
AlgoChronicle
Custom Gem
That's an excellent point! To maintain consistency and accurately reflect the source of the problem, I'll update the link and platform fields in the Contains Duplicate README to reference the NeetCode 150 list.

Here is the updated related_contains_duplicate/README.md.

1. Updated Problem README (related_contains_duplicate/README.md)
   The metadata has been adjusted to use the NeetCode platform and link.

## Markdown

dayNumber: 1
title: Duplicate Integer
platform: NeetCode 150
link: https://neetcode.io/problems/duplicate-integer
difficulty: Easy
pattern: Hash Table / Set
approach: Use a HashSet/Unordered Set to track seen numbers.
optimized: O(n)
bruteforce: O(n²)
space: O(n)
date: 2025-10-23
commitHash: [INJECTED BY GITHUB ACTION]
tags:

- array
- hash-table

---

# Duplicate Integer (Contains Duplicate)

**Platform:** NeetCode 150 | **Difficulty:** Easy | **Pattern:** Hash Table

---

## Problem Description

Given an integer array `nums`, return **true** if any value appears **more than once** in the array, otherwise return **false**.

---

## Examples

**Example 1:**
Input: nums = [1, 2, 3, 3] Output: true

**Example 2:**
Input: nums = [1, 2, 3, 4] Output: false

---

## Approaches

### 1. Brute Force - O(N²)

**Idea:** Compare every element with every other element. Use nested loops to check if `nums[i] == nums[j]` where $i \ne j$.

**Time:** O(N²)
**Space:** O(1)

---

### 2. Hash Set (Optimized) - O(N) ⭐

**Idea:** This is the ideal use case for a **Hash Set**. Iterate through the array once, storing each number encountered in the set. Before adding a number, check if it already exists. If it does, you've found a duplicate and can immediately return `true`.

**Time:** $O(N)$ - Single pass with $O(1)$ average lookup/insertion.
**Space:** $O(N)$ - To store the set, where $N$ is the number of elements.

---

## Solutions

- 🐍 [solution.py](./solution.py) - Python implementation
- ☕ [solution.java](./solution.java) - Java implementation
- ⚡ [solution.cpp](./solution.cpp) - C++ implementation

---

## Complexity Analysis

| Approach    | Time  | Space |
| ----------- | ----- | ----- |
| Brute Force | O(N²) | O(1)  |
| Hash Set    | O(N)  | O(N)  |

**Winner:** Hash Set ⭐
