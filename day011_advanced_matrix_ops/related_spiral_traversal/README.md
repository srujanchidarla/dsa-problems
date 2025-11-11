---
dayNumber: 11
title: "Spiral Traversal of Matrix"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-primary/problems/spiral-traversal-of-matrix"
difficulty: "Medium"
pattern: "Boundary Pointers"
approach: "Use four pointers (top, bottom, left, right) to define boundaries. Iterate through the four sides, shifting the boundaries inward after each pass."
optimized: "O(N²)"
bruteforce: "O(N²)"
space: "O(1)"
date: "2025-11-08"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - matrix
  - traversal
  - boundary-logic
---

# Spiral Traversal of Matrix

**Platform:** Smart Interviews | **Difficulty:** Medium | **Pattern:** Boundary Pointers

---

## Problem Description

Given a 2D square matrix, print all its elements in a spiral (clockwise) order. The problem specifically asks for a solution **without using extra space** (e.g., using a visited array).

## Approaches

### 1. Boundary Pointers (Optimal) - $O(N^2)$ ⭐

**Idea:** The complexity is fixed at $O(N^2)$ as every element must be visited. The optimal method uses four pointers to track the current processing boundaries: `top`, `bottom`, `left`, and `right`.

The algorithm loops while the boundaries haven't crossed (`top <= bottom` and `left <= right`), executing four steps: traverse right (increment `top`), traverse down (decrement `right`), traverse left (decrement `bottom`), traverse up (increment `left`).

**Time:** $O(N^2)$
**Space:** $O(1)$ (Excluding output storage).

---
