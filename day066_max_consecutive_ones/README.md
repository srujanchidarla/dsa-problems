# Day 066 - Max Consecutive Ones

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (485)   |
| Difficulty | Easy             |
| Topic      | Arrays           |
| Pattern    | Single Pass / Running Count |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

Given a binary array `nums`, return the maximum number of consecutive `1`s in the array.

*Added 2026-11-01 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  nums = [1,1,0,1,1,1]
Output: 3

Input:  nums = [1,0,1,1,0,1]
Output: 2

Input:  nums = [0]
Output: 0
```

---

## Pattern Recognition

**Single Pass / Running Count** — you only need two numbers while walking the array once: the length of the run you are in right now, and the best run you have seen so far. A `0` resets the current run; a `1` grows it.

---

## Approach

### Brute Force — Count From Every Start, O(n²)

```
best = 0
for i in range(len(nums)):
    count = 0
    for j in range(i, len(nums)):
        if nums[j] == 0: break
        count += 1
    best = max(best, count)
return best
```

### Optimized — One Pass, O(n)

```
count = 0
best = 0
for v in nums:
    count = count + 1 if v == 1 else 0
    best = max(best, count)
return best
```

---

## Complexity

| Approach         | Time  | Space | Notes                          |
| ---------------- | ----- | ----- | ------------------------------ |
| Count every start| O(n²) | O(1)  | Re-counts runs from each index |
| One pass         | O(n)  | O(1)  | Reset on 0, grow on 1          |
