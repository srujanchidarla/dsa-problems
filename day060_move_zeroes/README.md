# Day 060 - Move Zeroes

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (283)   |
| Difficulty | Easy             |
| Topic      | Arrays / Two Pointers |
| Pattern    | Two Pointers (Read/Write) |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

Given an integer array `nums`, move all `0`s to the end of it while maintaining the relative order of the non-zero elements. Do it in-place, without making a copy of the array.

*Added 2026-10-30 from Srujan's LeetCode solved list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Input:  nums = [0]
Output: [0]
```

---

## Pattern Recognition

**Two Pointers (Read / Write)** — the same shape as Remove Element (Day 040) and Remove Duplicates (Day 036): one pointer reads every element, the other writes only the ones we keep. Zeros are simply never written; the tail is filled with zeros at the end.

---

## Approach

### Brute Force — Extra Array, O(n) time, O(n) space

```
result = [x for x in nums if x != 0]
result += [0] * (n - len(result))
copy result back into nums
```

### Optimized — Read/Write Pointers, O(n) time, O(1) space

```
write = 0
for read in 0..n-1:
    if nums[read] != 0:
        nums[write] = nums[read]
        write += 1
for i in write..n-1:
    nums[i] = 0
```

---

## Complexity

| Approach     | Time | Space | Notes                          |
| ------------ | ---- | ----- | ------------------------------ |
| Extra array  | O(n) | O(n)  | Simple, violates in-place      |
| Read / write | O(n) | O(1)  | Keeps order, fills tail with 0 |
