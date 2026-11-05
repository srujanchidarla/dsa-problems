# Day 070 - Find All Numbers Disappeared in an Array

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (448)   |
| Difficulty | Easy             |
| Topic      | Arrays           |
| Pattern    | In-Place Marking |
| Time       | O(n)             |
| Space      | O(1) extra       |

---

## Problem Statement

Given an array `nums` of `n` integers where each value is in the range `[1, n]`, return an array of all the integers in `[1, n]` that do not appear in `nums`.

*Added 2026-11-05 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Input:  nums = [1,1]
Output: [2]

Input:  nums = [1,2,3]
Output: []
```

---

## Pattern Recognition

**In-Place Marking** — the values are already valid indices (1..n), so the array can be its own checklist. For each value `v`, flip the sign of the element at index `v - 1`. After one pass, the indices that are still positive were never visited — their numbers are the missing ones. No extra set needed.

---

## Approach

### Brute Force — Check Every Value, O(n²)

```
for x from 1 to n:
    if x never appears in nums (linear scan): add x to the answer
```

### Optimized — In-Place Sign Marking, O(n)

```
for v in nums:
    i = abs(v) - 1
    if nums[i] > 0: nums[i] = -nums[i]   # mark value (i + 1) as seen
answer = [i + 1 for i where nums[i] > 0]  # never marked = missing
```

---

## Complexity

| Approach         | Time  | Space      | Notes                          |
| ---------------- | ----- | ---------- | ------------------------------ |
| Check every value| O(n²) | O(1) extra | Re-scans the array per value   |
| In-place marking | O(n)  | O(1) extra | The array is its own checklist |
