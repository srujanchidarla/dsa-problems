# Day 031 - Number Distribution

| Field      | Details                 |
| ---------- | ----------------------- |
| Platform   | Smart Interviews (Hive) |
| Difficulty | Easy                    |
| Topic      | Arrays                  |
| Pattern    | Counting + Conditionals |
| Time       | O(n)                    |
| Space      | O(1)                    |

---

## Problem Statement

Given N numbers, count how many are **positive**, how many are **negative**, and how many are **zero**.

---

## Input / Output

```
Input:
  Line 1: Integer N — count of numbers
  Line 2: N space-separated integers

Output:
  Three integers on separate lines:
    count of positives
    count of negatives
    count of zeros

Example:
  Input:  6
          3 -1 0 7 -4 0
  Output: 2
          2
          2
```

---

## Constraints

```
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9
```

---

## Understanding the Problem

- Walk through every number once
- Bucket each number into one of three categories: positive, negative, or zero
- Three counters, one loop — that's the entire solution

### Edge Cases

- All zeros → pos=0, neg=0, zero=N
- All positive → neg=0, zero=0
- All negative → pos=0, zero=0
- Single element → still works fine

---

## Pattern Recognition

**Counting + Conditionals** — Maintain separate counters and increment the right one
based on a condition. This pattern appears constantly in array problems.

---

## Approach

### Optimized — O(n)

```
Initialize pos=0, neg=0, zero=0
For each number in array:
    if number > 0  → pos++
    if number < 0  → neg++
    if number == 0 → zero++
Print pos, neg, zero
```

No brute force needed — this is already optimal.

---

## Complexity

| Approach  | Time | Space | Notes                        |
| --------- | ---- | ----- | ---------------------------- |
| Optimized | O(n) | O(1)  | Single pass, three variables |

---

## Video Resources

| Topic                   | Link                                        |
| ----------------------- | ------------------------------------------- |
| Arrays Basics — Striver | https://www.youtube.com/watch?v=37E9ckMDdTk |

---

## Online Compiler

https://onecompiler.com/
