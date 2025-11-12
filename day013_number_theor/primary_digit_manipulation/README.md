---
dayNumber: 13
title: "Count Digits and Reverse Number"
platform: "TakeUForward"
link: "https://takeuforward.org/plus/dsa/problems/count-all-digits-of-a-number (and Reverse a Number)"
difficulty: "Easy"
pattern: "Digit Traversal (Modulo/Division)"
approach: "Use a while loop that continues while N > 0. Inside the loop, extract the last digit (N % 10) and update N (N /= 10)."
optimized: "O(log₁₀ N)"
bruteforce: "O(log₁₀ N)"
space: "O(1)"
date: "2025-11-10"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - math
  - digits
  - traversal
---

# Count Digits and Reverse Number

**Platform:** TakeUForward | **Difficulty:** Easy | **Pattern:** Digit Traversal

---

## Problem Description

The task is to master the fundamental technique of processing a number digit by digit:

1.  **Count Digits:** Given an integer $N$, count how many digits it has.
2.  **Reverse a Number:** Given an integer $N$, return the number formed by reversing its digits.

## Approaches

### 1. Modulo and Division (Optimal) - $O(\log_{10} N)$ ⭐

**Idea:** The time complexity is logarithmic because we reduce the number of digits by a factor of 10 in each constant-time iteration.

**Reverse Number:** Build the reversed number: `reversed = reversed * 10 + last_digit`.

---
