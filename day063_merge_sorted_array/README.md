# Day 063 - Merge Sorted Array

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (88)    |
| Difficulty | Easy             |
| Topic      | Arrays / Two Pointers |
| Pattern    | Merge from the End |
| Time       | O(m + n)         |
| Space      | O(1)             |

---

## Problem Statement

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively. Merge `nums2` into `nums1` as one sorted array. `nums1` has length `m + n`: its first `m` elements are the real values and its last `n` elements are `0`s, there only as space for the merge. Do it in place — do not return anything, just modify `nums1`.

*Added 2026-10-30 from Srujan's LeetCode solved list (photo) — it was open as a browser tab in the photo but not previously in the repo.*

---

## Input / Output

```
Input:  nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Input:  nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]

Input:  nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
```

---

## Pattern Recognition

**Merge from the End** — merging from the front would overwrite values in `nums1` you still need. The empty `0` slots sit at the *end*, so work backwards: at each step, the largest remaining element (the larger of the two tails) belongs in the last free slot. That slot is always safe to write, because everything after it is already placed.

---

## Approach

### Brute Force — Copy, Then Sort, O((m + n) log(m + n))

```python
nums1[m:] = nums2     # fill the empty tail with nums2
nums1.sort()          # sort the whole array
```

### Optimized — Three Pointers from the End, O(m + n) time, O(1) space

```python
p1 = m - 1            # last real element of nums1
p2 = n - 1            # last element of nums2
p  = m + n - 1        # last free slot of nums1
while p2 >= 0:
    if p1 >= 0 and nums1[p1] > nums2[p2]:
        nums1[p] = nums1[p1]
        p1 -= 1
    else:
        nums1[p] = nums2[p2]
        p2 -= 1
    p -= 1
```

When `nums2` is exhausted, anything left in `nums1` is already in place — so the loop only needs to run until `p2` runs out. (If `p1` runs out first, the remaining `nums2` elements just copy straight across.)

---

## Complexity

| Approach              | Time            | Space | Notes                          |
| --------------------- | --------------- | ----- | ------------------------------ |
| Copy, then sort       | O((m+n) log(m+n)) | O(1) | Ignores that both are sorted   |
| Three pointers, end   | O(m + n)        | O(1)  | In place, uses the free tail   |
