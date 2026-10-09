# Day 052 - Product of Array Except Self

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (238)   |
| Difficulty | Medium           |
| Topic      | Arrays / Prefix-Suffix |
| Pattern    | Prefix & Suffix Passes |
| Time       | O(n)             |
| Space      | O(1) extra       |

---

## Problem Statement

Given an integer array `nums`, return an array `answer` such that `answer[i]` equals the product of all the elements of `nums` except `nums[i]`. You must not use division, and the solution must run in O(n) time.

*Imported 2026-10-09 from NeetCode auto-sync. Note: the synced submissions were the O(n²) brute force — kept below, with the O(n) optimized version added.*

---

## Input / Output

```
Input:  nums = [1,2,3,4]
Output: [24,12,8,6]
```

---

## Pattern Recognition

**Prefix & Suffix Passes** — `answer[i] = (product of everything left of i) × (product of everything right of i)`. Two passes, no division.

---

## Approach

### Brute Force — Nested Products, O(n²)

```
for i: answer[i] = product of all nums[j], j != i
```

### Optimized — Prefix then Suffix, O(n)

```
answer[i] = prefix product up to i-1      # left-to-right pass
answer[i] *= suffix product from i+1     # right-to-left pass
```

---

## Complexity

| Approach      | Time  | Space      | Notes                          |
| ------------- | ----- | ---------- | ------------------------------ |
| Nested loops  | O(n²) | O(1) extra | Recomputes products per index  |
| Prefix+suffix | O(n)  | O(1) extra | Two passes, output array only  |
