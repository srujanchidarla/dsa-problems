---
dayNumber: 11
title: "Rotation of Matrix (90 Degrees Clockwise)"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-primary/problems/rotation-of-matrix"
difficulty: "Medium"
pattern: "In-Place Transpose & Reverse"
approach: "To achieve a 90-degree clockwise rotation in-place, first transpose the matrix (swap A[i][j] with A[j][i]), and then reverse each row."
optimized: "O(N²)"
bruteforce: "O(N²)"
space: "O(1)"
date: "2025-11-08"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - matrix
  - in-place
  - transformation
---

# Rotation of Matrix (90 Degrees Clockwise)

**Platform:** Smart Interviews | **Difficulty:** Medium | **Pattern:** In-Place Transformation

---

## Problem Description

Given a 2D square matrix, rotate it by 90 degrees clockwise. The note suggests solving this **in-place** (without using a second $N \times N$ matrix).

## Approaches

### 1. In-Place Transpose and Reverse (Optimal) - $O(N^2)$ ⭐

**Idea:** A 90-degree clockwise rotation is mathematically equivalent to two simpler operations:

1.  **Transpose:** Flip the matrix over its main diagonal ($A[i][j] \leftrightarrow A[j][i]$).
2.  **Reverse Rows:** Reverse the order of elements in each individual row.

### 2. Brute Force (Extra Space) - $O(N^2)$

**Idea:** Create a new $N \times N$ matrix $B$. Assign elements using the rotation rule: $B[j][N-1-i] = A[i][j]$.

**Time:** $O(N^2)$
**Space:** $O(N^2)$

---
