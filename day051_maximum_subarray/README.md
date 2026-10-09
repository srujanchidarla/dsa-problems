# Day 051 - Maximum Subarray

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (53)    |
| Difficulty | Medium           |
| Topic      | Arrays / DP      |
| Pattern    | Kadane's Algorithm |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

Given an integer array `nums`, find the subarray with the largest sum, and return its sum.

*Imported 2026-10-09 from NeetCode auto-sync (reviewed).*

---

## Input / Output

```
Input:  nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6
```

---

## Pattern Recognition

**Kadane's Algorithm** — at each position, decide: start fresh here, or extend the running subarray? Track the best answer seen.

---

## Approach

### Brute Force — All Subarrays, O(n²)

```
best = -inf
for i in range(n):
    s = 0
    for j in range(i, n):
        s += nums[j]
        best = max(best, s)
```

### Optimized — Kadane's, O(n)

```
cur = best = nums[0]
for x in nums[1:]:
    cur = max(x, cur + x)   # start fresh or extend
    best = max(best, cur)
```

---

## Complexity

| Approach     | Time  | Space | Notes                          |
| ------------ | ----- | ----- | ------------------------------ |
| All subarrays| O(n²) | O(1)  | Re-sums overlapping ranges     |
| Kadane's     | O(n)  | O(1)  | One pass, restart-or-extend    |
