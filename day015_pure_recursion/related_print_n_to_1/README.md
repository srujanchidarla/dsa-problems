---
dayNumber: 15
title: "Print N to 1 and 1 to N"
platform: "TakeUForward"
link: "https://takeuforward.org/plus/dsa/problems/print-1-to-n-using-recursion"
difficulty: "Easy"
pattern: "State Preservation / Pre vs. Post Recursion"
approach: "The difference between the two is where the print statement is placed relative to the recursive call. Printing before the call manages state, printing after the call uses the returning stack."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(N)"
date: "2025-11-12"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - recursion
  - functional
  - call-stack
---

# Print N to 1 and 1 to N (Recursive)

**Platform:** TakeUForward | **Difficulty:** Easy | **Pattern:** Call Stack Management

---

## Problem Description

Implement two recursive functions:

1.  Print numbers from $N$ down to 1.
2.  Print numbers from 1 up to $N$.

## Approaches

### 1. Pre vs. Post Recursion (Optimal) - $O(N)$ ⭐

**Idea:** Both solutions require $N$ recursive calls, making the time $\text{O}(N)$. The difference demonstrates how the call stack functions:

- **N to 1:** The print statement executes **before** the recursive call.
- **1 to N:** The recursive call is made first, building up the stack. The print statement executes **after** the recursive call returns, unwinding the stack from 1 to N.

---
