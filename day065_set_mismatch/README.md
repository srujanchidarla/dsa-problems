# Day 065 - Set Mismatch

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (645)   |
| Difficulty | Easy             |
| Topic      | Arrays           |
| Pattern    | Math / Set       |
| Time       | O(n)             |
| Space      | O(n)             |

---

## Problem Statement

You have a set of integers `1` to `n`. One number is duplicated (appears twice) and one number is missing. Return `[duplicated, missing]`.

*Added 2026-11-01 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  nums = [1,2,2,4]
Output: [2,3]

Input:  nums = [1,1]
Output: [1,2]

Input:  nums = [2,2]
Output: [2,1]
```

---

## Pattern Recognition

**Math / Set** — the numbers are supposed to be exactly `1..n`, so the *expected* sum is known: `n(n+1)/2`. The duplicate is the only value that appears twice, and the missing number is the gap between the expected sum and the real sum once the duplicate is removed.

---

## Approach

### Brute Force — Count Every Value, O(n²)

```
for x from 1 to n:
    count how many times x appears in nums
    if count == 2: duplicate = x
    if count == 0: missing = x
return [duplicate, missing]
```

### Optimized — Sum and Set, O(n)

```
seen = set(nums)                 # duplicate = the value that fails to grow the set
duplicate = the value seen twice
missing = n(n+1)/2 - (sum(nums) - duplicate)
return [duplicate, missing]
```

Why it works: `sum(nums) - duplicate` is the sum of the set with no repeats, so the expected sum minus that sum is exactly the missing number.

---

## Complexity

| Approach         | Time  | Space | Notes                          |
| ---------------- | ----- | ----- | ------------------------------ |
| Count every value| O(n²) | O(1)  | Re-scans the array per value   |
| Sum and set      | O(n)  | O(n)  | One pass, uses the known total |
