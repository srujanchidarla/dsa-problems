---
dayNumber: 10
title: "Valid Parentheses"
platform: "LeetCode"
link: "https://leetcode.com/problems/valid-parentheses/"
difficulty: "Easy"
pattern: "Stack / Hash Map Lookup"
approach: "Use a Stack to store opening brackets. Use a Hash Map for O(1) lookup to find the matching opener when a closing bracket is encountered."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(N)"
date: "2025-11-07"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - string
  - stack
  - hash-map
---

# Valid Parentheses

**Platform:** LeetCode | **Difficulty:** Easy | **Pattern:** Stack

---

## Problem Description

Given a string $S$ containing only the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. A valid string requires opening brackets to be closed by the same type of bracket and in the correct order.

## Approaches

### 1. Stack and Hash Map (Optimal) - $O(N)$ ⭐

**Idea:** The Stack is the perfect data structure for validating LIFO (Last-In, First-Out) order constraints like nesting.

1.  Initialize an empty **Stack**.
2.  Initialize a **Hash Map** mapping closers to openers (e.g., `'}' \to '{'$).
3.  Iterate through the string: push openers onto the stack. When a closer is found, pop the stack and check for a match using the Hash Map.

**Time:** $\text{O}(N)$ (Each character is pushed/popped at most once).
**Space:** $\text{O}(N)$ (Worst case: stack stores all opening brackets).

---
