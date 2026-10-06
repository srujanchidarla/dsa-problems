# Day 040 - Remove Element

| Field      | Details                   |
| :--------- | :------------------------ |
| Platform   | LeetCode (27)             |
| Difficulty | Easy                      |
| Topic      | Arrays / Two Pointers     |
| Pattern    | Two Pointers (Read/Write) |
| Time       | O(n)                      |
| Space      | O(1)                      |

---

## Problem Statement

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` **in-place**. The order of the elements may be changed.

Return `k`, the number of elements in `nums` which are not equal to `val`. The first `k` elements of `nums` must contain those elements; the rest does not matter.

---

## Input / Output

```
Input:  nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]

Input:  nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]   (any order of the first 5 is accepted)
```

---

## Constraints

```
0 ≤ nums.length ≤ 100
0 ≤ nums[i] ≤ 50
0 ≤ val ≤ 100
```

---

## Understanding the Problem

- Keep everything that is **not** `val`, packed at the front
- In-place → no second array
- Order may change → allows the swap-with-end trick

### Edge Cases

- Empty array → `k = 0`
- Every element equals `val` → `k = 0`
- `val` not present → `k = n`

---

## Pattern Recognition

**Two Pointers (Read / Write)** — same shape as Remove Duplicates (Day 036), only the keep-condition changes: `nums[read] != val`.

Variant: when `val` is rare, **swap with the end** to minimise writes, since order doesn't matter.

---

## Approach

### Read / Write — O(n)

```
write = 0
for read in 0..n-1:
    if nums[read] != val:
        nums[write++] = nums[read]
return write
```

### Swap with End — O(n), fewer writes when val is rare

```
i = 0, n = len
while i < n:
    if nums[i] == val: nums[i] = nums[n-1]; n--   (re-check i)
    else:              i++
return n
```

---

## Complexity

| Approach      | Time | Space | Notes                              |
| ------------- | ---- | ----- | ---------------------------------- |
| Read / Write  | O(n) | O(1)  | Keeps relative order               |
| Swap with End | O(n) | O(1)  | Fewer writes, order not preserved  |

---

## Online Compiler

https://onecompiler.com/
