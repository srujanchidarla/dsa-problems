---
dayNumber: 12
title: "Jump Game"
platform: "LeetCode"
link: "https://leetcode.com/problems/jump-game/"
difficulty: "Medium"
pattern: "Greedy Array Traversal"
approach: "Iterate backward from the target (end of the array). Maintain the 'goal' index. If a position can reach the goal, update the goal to that position. The answer is YES if the goal reaches index 0."
optimized: "O(N)"
bruteforce: "O(N²)"
space: "O(1)"
date: "2025-11-09"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - array
  - greedy
  - traversal
---

# Jump Game

**Platform:** LeetCode | **Difficulty:** Medium | **Pattern:** Greedy Traversal

---

## Problem Description

Given an array of non-negative integers `nums`, where `nums[i]` represents the maximum jump length from position $i$. Determine if you can reach the last index starting from the first index (index 0).

## Approaches

### 1. Backward Greedy Traversal (Optimal) - $O(N)$ ⭐

**Idea:** Instead of checking all paths forward (which could be $O(N^2)$), we work backward from the goal. This is the optimal **Greedy** choice.

1.  Set the `goal` to the last index ($N-1$).
2.  Iterate backward from $i = N-2$ down to 0.
3.  At index $i$, check if the current position can reach the `goal`: $i + \text{nums}[i] \ge \text{goal}$.
4.  If it can, update the `goal` to $i$ (because $i$ is now the new, closer valid starting point).
5.  After the loop, return TRUE if the `goal` is 0.

### 2. Brute Force / Recursion - $O(N^2)$ or $O(2^N)$

**Idea:** Try every possible jump from the current position using recursion or a complex nested loop structure. This leads to redundant calculations and poor performance.

---
