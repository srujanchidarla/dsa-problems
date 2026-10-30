# Day 056 - Concatenation of Array

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (1929)  |
| Difficulty | Easy             |
| Topic      | Arrays           |
| Pattern    | Build by Index / Modulo |
| Time       | O(n)             |
| Space      | O(n)             |

---

## Problem Statement

Given an integer array `nums` of length `n`, return an array `ans` of length `2n` where `ans[i] == nums[i]` and `ans[i + n] == nums[i]` for `0 <= i < n`. In plain words: write the array twice, back to back.

*Added 2026-10-30 from Srujan's LeetCode solved list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  nums = [1,2,1]
Output: [1,2,1,1,2,1]

Input:  nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
```

---

## Pattern Recognition

**Build by Index** — the second half is a copy of the first, shifted by `n`. Every output position maps to exactly one input position: `ans[i] = nums[i % n]`.

---

## Approach

### Brute Force — Modulo Indexing, O(n)

```
for i in 0..2n-1:
    ans[i] = nums[i % n]      # wrap around to the start for the second half
```

### Optimized — Fill Both Halves in One Pass, O(n)

```
for i in 0..n-1:
    ans[i]     = nums[i]      # first copy
    ans[i + n] = nums[i]      # second copy, same step
```

Same O(n) time, but one loop instead of two passes / modulo on every index.

---

## Complexity

| Approach        | Time | Space | Notes                          |
| --------------- | ---- | ----- | ------------------------------ |
| Modulo indexing | O(n) | O(n)  | Output array is required       |
| Fill both halves| O(n) | O(n)  | One pass, no modulo            |
