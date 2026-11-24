# Day 079 - Contains Duplicate II

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (219)   |
| Difficulty | Easy             |
| Topic      | Arrays / Hash Map |
| Pattern    | Last-Seen Index  |
| Time       | O(n)             |
| Space      | O(n)             |

---

## Problem Statement

Given an integer array `nums` and an integer `k`, return `true` *if there are two **distinct indices*** `i` *and* `j` *in the array such that* `nums[i] == nums[j]` *and* `abs(i - j) <= k`.

""" + PROV + r"""

---

## Input / Output

```
Input:  nums = [1,2,3,1], k = 3
Output: true

Input:  nums = [1,0,1,1], k = 1
Output: true

Input:  nums = [1,2,3,1,2,3], k = 2
Output: false
```

---

## Pattern Recognition

**Remember the last-seen index** — a duplicate only counts if the two copies sit within `k` of each other, so you never need the full history of a value, just where you saw it most recently. One pass with a map from value to latest index answers every check in O(1).

---

## Approach

### Brute Force — Check Every Pair Within k, O(n * k)

```
for i in range(n):
    for j in range(i + 1, min(i + k + 1, n)):
        if nums[i] == nums[j]: return True
return False
```

Correct, but it re-compares the same neighborhood over and over.

### Optimized — Hash Map of Last-Seen Index, O(n)

```
last = {}                       # value -> latest index
for i, x in enumerate(nums):
    if x in last and i - last[x] <= k:
        return True
    last[x] = i
return False
```

Example: `[1,2,3,1]`, `k = 3` — the second `1` is at index 3, the last-seen `1` was at index 0, and `3 - 0 = 3 <= 3`, so `true`. In `[1,2,3,1,2,3]` with `k = 2`, every repeat is 3 apart — too far, so `false`.

---

## Complexity

| Approach          | Time    | Space | Notes                                        |
| ----------------- | ------- | ----- | -------------------------------------------- |
| Check pairs in k  | O(n * k)| O(1)  | Re-scans each value's neighborhood           |
| Last-seen map     | O(n)    | O(n)  | One lookup per number, only latest index kept |
