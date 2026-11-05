# Day 069 - How Many Numbers Are Smaller Than the Current Number

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (1365)  |
| Difficulty | Easy             |
| Topic      | Arrays           |
| Pattern    | Counting Sort / Prefix Sums |
| Time       | O(n)             |
| Space      | O(1) extra (values bounded 0..100) |

---

## Problem Statement

Given the array `nums`, for each `nums[i]` find out how many numbers in the array are smaller than it. Return the answer in an array.

*Added 2026-11-05 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  nums = [8,1,2,2,3]
Output: [4,0,1,1,3]

Input:  nums = [6,5,4,8]
Output: [2,1,0,3]

Input:  nums = [7,7,7,7]
Output: [0,0,0,0]
```

---

## Pattern Recognition

**Counting Sort / Prefix Sums** — the values are bounded (0 to 100), so instead of comparing every pair, count how many times each value appears, then turn those counts into "how many are smaller than x" with a running total. One pass to count, one pass to answer.

---

## Approach

### Brute Force — Compare Every Pair, O(n²)

```
for i in range(len(nums)):
    answer[i] = count of j where nums[j] < nums[i]
```

### Optimized — Count + Prefix Sums, O(n)

```
count[v] = how many times value v appears
smaller[v] = count[0] + count[1] + ... + count[v-1]   # running total
answer[i] = smaller[nums[i]]
```

---

## Complexity

| Approach         | Time  | Space      | Notes                          |
| ---------------- | ----- | ---------- | ------------------------------ |
| Compare pairs    | O(n²) | O(1) extra | Simple, re-compares everything |
| Count + prefix   | O(n)  | O(101)     | Bounded values make it free    |
