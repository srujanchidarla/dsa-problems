---
dayNumber: 12
title: "Alternate Seating"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/alternate-seating"
difficulty: "Medium"
pattern: "Greedy Allocation / Boundary Check"
approach: "Iterate through the seats and, at each vacant spot (0), check if it meets the no-neighbor condition (both left and right are empty). If it does, 'seat' a person there (by setting the seat to 1) and decrement the required people count N."
optimized: "O(M)"
bruteforce: "O(M²)"
space: "O(1)"
date: "2025-11-09"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - array
  - greedy
  - allocation
---

# Alternate Seating

**Platform:** Smart Interviews | **Difficulty:** Medium | **Pattern:** Greedy Allocation

---

## Problem Description

Given $N$ people needing seats and an array of $M$ seats (0=vacant, 1=occupied), find if all $N$ people can be seated such that **no two people sit next to each other** (i.e., new person must have empty seats on both sides, if they exist).

## Approaches

### 1. Greedy Single Pass (Optimal) - $O(M)$ ⭐

**Idea:** The best strategy is to be greedy: whenever a valid empty spot is found, take it immediately, as taking a spot can only improve the chances for future people by reducing the required count $N$.

1.  Iterate through the seats $M$.
2.  At index $i$, check the three conditions for a valid seat:
    - Seat is empty (`seats[i] == 0`).
    - Left neighbor is empty (or index $i=0$).
    - Right neighbor is empty (or index $i=M-1$).
3.  If valid, set `seats[i] = 1` and decrement the required people count $N$.
4.  If $N$ reaches 0, the answer is YES. If the loop finishes with $N > 0$, the answer is NO.

**Time:** $O(M)$ (A single pass over the seats).
**Space:** $O(1)$ (Modification done in place).

---
