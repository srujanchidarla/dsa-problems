# Day 074 - Maximum Average Subarray I

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (643)   |
| Difficulty | Easy             |
| Topic      | Arrays / Sliding Window |
| Pattern    | Fixed-Size Sliding Window |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

You are given an integer array `nums` consisting of `n` elements, and an integer `k`.

Find a contiguous subarray whose length is equal to `k` that has the maximum average value and return this value. Any answer with a calculation error less than `10^-5` will be accepted.

*Added 2026-11-08 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75.

Input:  nums = [5], k = 1
Output: 5.0

Input:  nums = [0,1,1,3,3], k = 4
Output: 2.0
Explanation: Maximum average is (1 + 1 + 3 + 3) / 4 = 8 / 4 = 2.0.
```

---

## Pattern Recognition

**Fixed-size sliding window** — every candidate has exactly length `k`, so the window never grows or shrinks, it only slides. The sum of the next window is the old sum minus the element leaving and plus the element entering. And since dividing by `k` is the same for every window, comparing sums is the same as comparing averages — track the max *sum* and divide once at the end.

---

## Approach

### Brute Force — Recompute Every Window's Sum, O(n * k)

```
best = -inf
for i in range(n - k + 1):
    best = max(best, sum(nums[i:i+k]) / k)
return best
```

Each of the ~n windows costs O(k) to sum from scratch.

### Optimized — Sliding Window Sum, O(n)

```
window = sum(nums[0:k])
best = window
for i in range(k, n):
    window += nums[i] - nums[i - k]   # one in, one out
    best = max(best, window)
return best / k
```

---

## Complexity

| Approach              | Time   | Space | Notes                              |
| --------------------- | ------ | ----- | ---------------------------------- |
| Recompute every sum   | O(n*k) | O(1)  | Sums each window from scratch      |
| Sliding window sum    | O(n)   | O(1)  | One element in, one element out    |
