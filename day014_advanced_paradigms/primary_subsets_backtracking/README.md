---
dayNumber: 14
title: "Subsets (Backtracking)"
platform: "LeetCode"
link: "https://leetcode.com/problems/subsets/"
difficulty: "Medium"
pattern: "Backtracking / DFS"
approach: "Use a recursive function to explore all possibilities. At each element, make a choice: 1) Include the element and recurse. 2) Exclude the element and recurse. Backtrack by removing the element."
optimized: "O(N ⋅ 2ⁿ)"
bruteforce: "O(N ⋅ 2ⁿ)"
space: "O(N ⋅ 2ⁿ)"
date: "2025-11-11"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - recursion
  - backtracking
  - array
---

# Subsets (Backtracking)

**Platform:** LeetCode | **Difficulty:** Medium | **Pattern:** Backtracking

---

## Problem Description

Given an integer array `nums` of unique elements, return all possible subsets (the power set). The solution should not contain duplicate subsets.

## Approaches

### 1. Backtracking (Optimal) - $O(N \cdot 2^N)$ ⭐

**Idea:** The total number of subsets is $2^N$, and copying each subset takes $\text{O}(N)$ time, so the complexity is fixed. Backtracking simulates a Depth First Search (DFS) of the decision tree.

1.  Define a recursive function `backtrack(index, current_subset)`.
2.  **Base Case:** When `index` reaches the array length, a full subset has been formed. Add `current_subset` to the results.
3.  **Recursive Step:**
    - **Choice 1 (Include):** Add `nums[index]` to `current_subset`. Recurse with `index + 1`.
    - **Backtrack:** Remove `nums[index]` from `current_subset`.
    - **Choice 2 (Exclude):** Recurse with `index + 1`.

### 2. Bit Manipulation (Alternative Optimal) - $O(N \cdot 2^N)$

**Idea:** Since there are $2^N$ subsets, iterate from $0$ to $2^N - 1$. Each integer's binary representation acts as a bitmask: if the $j$-th bit is set (1), include the $j$-th element from `nums`.

---
