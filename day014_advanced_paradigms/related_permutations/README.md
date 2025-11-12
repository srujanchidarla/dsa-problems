---
dayNumber: 14
title: "Permutations (Backtracking)"
platform: "LeetCode"
link: "https://leetcode.com/problems/permutations/"
difficulty: "Medium"
pattern: "Backtracking / State Management"
approach: "Use a recursive function. At each step, iterate through the elements not yet included in the current permutation. This requires tracking the state of which numbers are used."
optimized: "O(N ⋅ N!)"
bruteforce: "O(N ⋅ N!)"
space: "O(N ⋅ N!)"
date: "2025-11-11"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - recursion
  - backtracking
  - state-management
---

# Permutations (Backtracking)

**Platform:** LeetCode | **Difficulty:** Medium | **Pattern:** State Management

---

## Problem Description

Given an array `nums` of distinct integers, return all the possible permutations.

## Approaches

### 1. Backtracking with Swap/Visited Array (Optimal) - $O(N \cdot N!)$ ⭐

**Idea:** The total number of permutations is $N!$. Since copying the result takes $\text{O}(N)$, the complexity is fixed. Permutations require managing which elements are _available_ at the current depth of recursion.

1.  **State Tracking:** Use a boolean array (or hash set) to mark elements as `visited`.
2.  Define a recursive function `backtrack(current_permutation)`.
3.  **Base Case:** If `current_permutation` is full (size $N$), add it to results.
4.  **Recursive Step:** Iterate through the _entire_ input array. If an element `nums[i]` is not `visited`:
    - **Action:** Mark `nums[i]` as visited, add it to the `current_permutation`.
    - **Recurse:** Call `backtrack(...)`.
    - **Backtrack:** Unmark `nums[i]` as visited (remove from `current_permutation`).

---
