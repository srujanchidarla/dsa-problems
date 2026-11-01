# Day 064 - Median of Two Sorted Arrays

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (4)     |
| Difficulty | Hard             |
| Topic      | Arrays           |
| Pattern    | Binary Search / Partition |
| Time       | O(log(min(m, n))) |
| Space      | O(1)             |

---

## Problem Statement

Given two sorted arrays `nums1` and `nums2`, return the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

*Added 2026-11-01 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  nums1 = [1,3], nums2 = [2]
Output: 2.00000

Input:  nums1 = [1,2], nums2 = [3,4]
Output: 2.50000

Input:  nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
```

---

## Pattern Recognition

**Binary Search Partition** — the median is the point where the merged array splits in half. Cut both arrays so the left half holds exactly half the elements, with every left element <= every right element. Then the median is just the border values. You binary-search the cut in the *shorter* array, which is why the time is O(log(min(m, n))).

---

## Approach

### Brute Force — Merge and Sort, O((m+n) log(m+n))

```
merged = sorted(nums1 + nums2)
n = len(merged)
return merged[n // 2] if n is odd else (merged[n // 2 - 1] + merged[n // 2]) / 2
```

### Optimized — Binary Search Partition, O(log(min(m, n)))

```
# make nums1 the shorter array
# binary search a cut i in nums1, j = half - i in nums2
# correct cut: nums1[i-1] <= nums2[j] and nums2[j-1] <= nums1[i]
# odd total: median = min(nums1[i], nums2[j])
# even total: median = (max(left) + min(right)) / 2
```

The cut is correct when the biggest element on the left of either array is still smaller than the smallest element on the right of the other. If `nums1[i-1] > nums2[j]`, the cut in nums1 is too far right — move it left. Otherwise move it right.

---

## Complexity

| Approach         | Time                | Space      | Notes                          |
| ---------------- | ------------------- | ---------- | ------------------------------ |
| Merge and sort   | O((m+n) log(m+n))   | O(m+n)     | Simple, ignores the sorted input |
| Binary partition | O(log(min(m, n)))   | O(1)       | The interview answer           |
