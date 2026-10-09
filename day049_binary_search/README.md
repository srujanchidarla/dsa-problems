# Day 049 - Binary Search

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (704)   |
| Difficulty | Easy             |
| Topic      | Searching        |
| Pattern    | Halving the Search Space |
| Time       | O(log n)         |
| Space      | O(1)             |

---

## Problem Statement

Given an array of integers `nums` sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. Return its index, or `-1` if it doesn't exist.

*Imported 2026-10-09 from NeetCode auto-sync (reviewed, debug prints removed).*

---

## Input / Output

```
Input:  nums = [-1,0,3,5,9,12], target = 9
Output: 4
```

---

## Pattern Recognition

**Halving the Search Space** — the array is sorted, so one comparison at the middle eliminates half the candidates. The `<=` loop condition and `mid ± 1` updates are the details that matter.

---

## Approach

### Brute Force — Linear Scan, O(n)

```
for i, x in enumerate(nums): if x == target: return i
return -1
```

### Optimized — Binary Search, O(log n)

```
left = 0, right = n - 1
while left <= right:
    mid = (left + right) // 2
    if nums[mid] == target: return mid
    if nums[mid] < target: left = mid + 1
    else: right = mid - 1
return -1
```

---

## Complexity

| Approach      | Time     | Space | Notes                          |
| ------------- | -------- | ----- | ------------------------------ |
| Linear scan   | O(n)     | O(1)  | Ignores sortedness             |
| Binary search | O(log n) | O(1)  | Halves candidates each step    |
