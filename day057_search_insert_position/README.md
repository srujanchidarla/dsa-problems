# Day 057 - Search Insert Position

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (35)    |
| Difficulty | Easy             |
| Topic      | Arrays / Binary Search |
| Pattern    | Binary Search    |
| Time       | O(log n)         |
| Space      | O(1)             |

---

## Problem Statement

Given a sorted array of distinct integers `nums` and a target value `target`, return the index if the target is found. If not, return the index where it would be inserted to keep the order.

*Added 2026-10-30 from Srujan's LeetCode solved list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  nums = [1,3,5,6], target = 5
Output: 2

Input:  nums = [1,3,5,6], target = 2
Output: 1

Input:  nums = [1,3,5,6], target = 7
Output: 4

Input:  nums = [1,3,5,6], target = 0
Output: 0
```

---

## Pattern Recognition

**Binary Search** — the array is sorted, so half the candidates can be thrown away at each step. When the loop ends, `lo` is exactly the first position `>= target` — the answer whether the target was found or not.

---

## Approach

### Brute Force — Linear Scan, O(n)

```
for i in 0..n-1:
    if nums[i] >= target: return i
return n
```

### Optimized — Binary Search, O(log n)

```
lo = 0, hi = n - 1
while lo <= hi:
    mid = (lo + hi) // 2
    if nums[mid] == target: return mid
    if nums[mid] < target:  lo = mid + 1
    else:                   hi = mid - 1
return lo        # insertion point
```

---

## Complexity

| Approach      | Time     | Space | Notes                          |
| ------------- | -------- | ----- | ------------------------------ |
| Linear scan   | O(n)     | O(1)  | Checks every element           |
| Binary search | O(log n) | O(1)  | `lo` is the answer on exit     |
