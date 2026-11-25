# Day 084 - Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (1343)  |
| Difficulty | Medium           |
| Topic      | Arrays / Sliding Window |
| Pattern    | Fixed-Size Sliding Window |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

Given an array of integers `arr` and two integers `k` and `threshold`, return *the number of sub-arrays of size* `k` *and average greater than or equal to* `threshold`.

*Added 2026-11-25 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).

Input:  arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
```

---

## Pattern Recognition

**Fixed-size sliding window** — every sub-array has the same length `k`, so the next window is just the previous one with one number dropped on the left and one added on the right. Keep a running sum instead of re-adding `k` numbers every time, and compare the sum against `k * threshold` (no floating-point division needed, since `sum / k >= threshold` is the same as `sum >= k * threshold`).

---

## Approach

### Brute Force — Re-Sum Every Window, O(n * k)

```
count = 0
for i in range(len(arr) - k + 1):
    if sum(arr[i:i + k]) / k >= threshold:
        count += 1
return count
```

Correct, but it adds up `k` numbers for every one of the `n - k + 1` windows.

### Optimized — Sliding Window, O(n)

```
window = sum(arr[:k])
count = 1 if window >= k * threshold else 0
for i in range(k, len(arr)):
    window += arr[i] - arr[i - k]    # slide: add the new right edge, drop the old left edge
    if window >= k * threshold:
        count += 1
return count
```

Example: `[2,2,2,2,5,5,5,8]`, `k = 3`, `threshold = 4` — window `[2,2,2]` sums to 6 (avg 2, no), slide to `[2,2,5]` (avg 3, no), slide to `[2,5,5]` (avg 4, yes), `[5,5,5]` (avg 5, yes), `[5,5,8]` (avg 6, yes) → `3`.

---

## Complexity

| Approach          | Time    | Space | Notes                                        |
| ----------------- | ------- | ----- | -------------------------------------------- |
| Re-sum each window | O(n * k) | O(1) | Adds k numbers per window, over and over     |
| Sliding window    | O(n)    | O(1)  | One addition and one subtraction per step    |
