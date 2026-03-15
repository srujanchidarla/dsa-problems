# Day 030 - Max Element in Array

| Field      | Details                 |
| ---------- | ----------------------- |
| Platform   | Smart Interviews (Hive) |
| Difficulty | Easy                    |
| Topic      | Arrays                  |
| Pattern    | Linear Scan             |
| Time       | O(n)                    |
| Space      | O(1)                    |

---

## Problem Statement

Given an array of N integers, find and return the **maximum element** in the array.

---

## Input / Output

```
Input:
  Line 1: Integer N — size of array
  Line 2: N space-separated integers

Output:
  Single integer — the maximum element

Example:
  Input:  5
          3 1 9 2 7
  Output: 9
```

---

## Constraints

```
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9
```

---

## Understanding the Problem

- We need to scan every element once and track the largest seen so far
- Values can be **negative** — so never initialize max to 0, use arr[0]
- N up to 10^5 means we need at most O(n) — no nested loops

### Edge Cases

- Single element array → return that element
- All negative numbers → max is the least negative (e.g. [-5, -3, -1] → -1)
- All same values → return that value

---

## Pattern Recognition

**Linear Scan** — Walk through the array once, tracking the best value seen.
This is the most fundamental array pattern. You will use it in 100+ problems.

---

## Approach

### Brute Force — O(n²)

For each element, compare it with every other element to check if it's the max.
Works but unnecessarily slow.

### Optimized — O(n)

```
Initialize max_val = arr[0]
For each element from index 1 onward:
    If element > max_val:
        Update max_val = element
Return max_val
```

---

## Complexity

| Approach    | Time  | Space | Notes                     |
| ----------- | ----- | ----- | ------------------------- |
| Brute Force | O(n²) | O(1)  | Nested loops              |
| Optimized   | O(n)  | O(1)  | Single pass, one variable |

---

## Video Resources

| Topic                  | Link                                        |
| ---------------------- | ------------------------------------------- |
| Arrays Intro — Striver | https://www.youtube.com/watch?v=37E9ckMDdTk |
| Arrays — NeetCode      | https://www.youtube.com/watch?v=P5W3pocEz6I |

---

## Online Compiler (for Hive problems)

https://onecompiler.com/
