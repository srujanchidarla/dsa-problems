# Day 032 - Odd and Even Sum

| Field      | Details                 |
| ---------- | ----------------------- |
| Platform   | Smart Interviews (Hive) |
| Difficulty | Easy                    |
| Topic      | Arrays                  |
| Pattern    | Linear Scan + Modulo    |
| Time       | O(n)                    |
| Space      | O(1)                    |

---

## Problem Statement

Given an array of N integers, find the **sum of all odd numbers** and the **sum of all even numbers** separately.

---

## Input / Output

```
Input:
  Line 1: Integer N
  Line 2: N space-separated integers

Output:
  Line 1: Sum of odd numbers
  Line 2: Sum of even numbers

Example:
  Input:  5
          1 2 3 4 5
  Output: 9
          6
```

---

## Constraints

```
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9
```

---

## Understanding the Problem

- Check each number: is it odd or even?
- Use **modulo operator** to determine parity
- Add to the correct accumulator

### Edge Cases

- All even → odd_sum = 0
- All odd → even_sum = 0
- Negative numbers: Python `-3 % 2 = 1` (odd ✅), Java `-3 % 2 = -1` → use `Math.abs(n % 2)`

---

## Pattern Recognition

**Linear Scan + Modulo** — `num % 2 == 0` means even, `num % 2 != 0` means odd.
Same structure as Number Distribution — just a different condition for bucketing.

---

## Approach

### Optimized — O(n)

```
Initialize odd_sum=0, even_sum=0
For each number:
    if num % 2 != 0 → odd_sum  += num
    else            → even_sum += num
Print odd_sum, even_sum
```

---

## Complexity

| Approach  | Time | Space | Notes                         |
| --------- | ---- | ----- | ----------------------------- |
| Optimized | O(n) | O(1)  | Single pass, two accumulators |

---

## Video Resources

| Topic                   | Link                                        |
| ----------------------- | ------------------------------------------- |
| Arrays Basics — Striver | https://www.youtube.com/watch?v=37E9ckMDdTk |

---

## Online Compiler

https://onecompiler.com/
