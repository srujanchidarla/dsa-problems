# Day 035 - Number of Steps to Reduce a Number to Zero

| Field      | Details                   |
| :--------- | :------------------------ |
| Platform   | LeetCode (1342)           |
| Difficulty | Easy                      |
| Topic      | Math / Bit Manipulation   |
| Pattern    | Simulation / Bit Counting |
| Time       | O(log n)                  |
| Space      | O(1)                      |

---

## Problem Statement

Given an integer `num`, return the number of steps to reduce it to zero.

In one step, if the current number is **even**, you divide it by `2`, otherwise you **subtract** `1` from it.

---

## Input / Output

```
Input:  num = 14
Output: 6
Explanation: 14 → 7 → 6 → 3 → 2 → 1 → 0

Input:  num = 8
Output: 4
Explanation: 8 → 4 → 2 → 1 → 0

Input:  num = 123
Output: 12
```

---

## Constraints

```
0 ≤ num ≤ 10^6
```

---

## Understanding the Problem

- Even → `num /= 2` (in binary: shift right, drops a `0`)
- Odd  → `num -= 1` (in binary: clears the lowest `1`)

### Edge Cases

- `num = 0` → 0 steps
- `num = 1` → 1 step

---

## Pattern Recognition

**Simulation**, or think in **binary**:
- Every `1` bit costs one subtract step
- Every bit position except the highest costs one divide step

```
steps = popcount(num) + (bitLength(num) - 1)     (num > 0)
```

Example: `14 = 1110₂` → 3 ones + (4 − 1) = **6** ✅

---

## Approach

### Brute Force — Simulation, O(log n)

```
steps = 0
while num > 0:
    if num is even: num /= 2
    else:           num -= 1
    steps++
return steps
```

### Optimized — Bit Counting, O(1) with builtins

```
if num == 0: return 0
return popcount(num) + bitLength(num) - 1
```

---

## Complexity

| Approach     | Time     | Space | Notes                                   |
| ------------ | -------- | ----- | --------------------------------------- |
| Simulation   | O(log n) | O(1)  | Straight from the problem statement     |
| Bit Counting | O(1)*    | O(1)  | *Hardware popcount / leading-zero count |

---

## Online Compiler

https://onecompiler.com/
