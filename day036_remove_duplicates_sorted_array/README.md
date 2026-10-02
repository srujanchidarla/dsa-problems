# Day 036 - Remove Duplicates from Sorted Array

| Field      | Details                    |
| :--------- | :------------------------- |
| Platform   | LeetCode (26)              |
| Difficulty | Easy                       |
| Topic      | Arrays / Two Pointers      |
| Pattern    | Two Pointers (Read/Write)  |
| Time       | O(n)                       |
| Space      | O(1)                       |

---

## Problem Statement

Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates **in-place** such that each unique element appears only **once**. The relative order of the elements should be kept the same.

Return `k`, the number of unique elements. The first `k` elements of `nums` must hold the unique elements in their original order; what is left beyond index `k` does not matter.

---

## Input / Output

```
Input:  nums = [1,1,2]
Output: 2, nums = [1,2,_]

Input:  nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
```

---

## Constraints

```
1 ≤ nums.length ≤ 3 * 10^4
-100 ≤ nums[i] ≤ 100
nums is sorted in non-decreasing order
```

---

## Understanding the Problem

- Array is **sorted** → duplicates are always **adjacent**
- Must be **in-place** → no second array for the answer
- Only the first `k` slots are checked

### Edge Cases

- Single element → `k = 1`
- All same → `k = 1`
- All distinct → `k = n`

---

## Pattern Recognition

**Two Pointers (Read / Write)** — `read` scans every element, `write` marks where the next unique value goes.
A new value is unique exactly when it differs from the last value written.

---

## Approach

### Brute Force — O(n) time | O(n) space

```
Collect unique values into a set / new list
Copy them back into nums
Return count
```

### Optimized — O(n) time | O(1) space

```
write = 1
for read in 1..n-1:
    if nums[read] != nums[write - 1]:
        nums[write] = nums[read]
        write++
return write
```

---

## Complexity

| Approach     | Time | Space | Notes                         |
| ------------ | ---- | ----- | ----------------------------- |
| Extra Array  | O(n) | O(n)  | Not truly in-place            |
| Two Pointers | O(n) | O(1)  | Uses sortedness, one pass     |

---

## Online Compiler

https://onecompiler.com/
