---
dayNumber: 13
title: "Check Palindrome and Armstrong Number"
platform: "TakeUForward"
link: "https://takeuforward.org/plus/dsa/problems/palindrome-number (and Armstrong Check)"
difficulty: "Easy"
pattern: "Digit Reversal and Power Summation"
approach: "Both require reversing the digits. For Palindrome, check if the original number equals the reversed number. For Armstrong, check if the original number equals the sum of its digits raised to the power of the total digit count."
optimized: "O(log₁₀ N)"
bruteforce: "O(log₁₀ N)"
space: "O(1)"
date: "2025-11-10"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - math
  - digits
  - palindrome
---

# Check Palindrome and Armstrong Number

**Platform:** TakeUForward | **Difficulty:** Easy | **Pattern:** Digit Reversal

---

## Problem Description

The task is to check two properties related to a number's digits:

1.  **Check Palindrome:** Determine if a number is the same when its digits are reversed (e.g., 121).
2.  **Armstrong Number:** Determine if a number equals the sum of its digits, each raised to the power of the total number of digits.

## Approaches

### 1. Digit Reversal/Summation (Optimal) - $O(\log_{10} N)$ ⭐

**Idea:** Both checks rely on the same core $\text{O}(\log N)$ digit traversal logic.

**Palindrome:** Reverse the number and compare to the original.

**Armstrong:** First, count the total digits ($D$). Then, calculate the sum of $(\text{last digit})^D$.

---
