# Day 043 - Two Sum

| Field      | Details                    |
| :--------- | :------------------------- |
| Platform   | LeetCode (1)               |
| Difficulty | Easy                       |
| Topic      | Arrays / Hash Map          |
| Pattern    | Hash Map Complement Lookup |
| Time       | O(n)                       |
| Space      | O(n)                       |

---

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to `target`.

*Re-solved 2026-10-09 as Day 1 of the foundations rebuild (originally logged as day001).*

---

## Input / Output

```
Input:  nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9
```

---

## Understanding the Problem

- For each `x`, the partner you need is `target - x`
- A hash map remembers every value seen so far and its index → O(1) lookups
- Check the complement BEFORE inserting the current element — this avoids pairing an element with itself (e.g. `nums = [3,3], target = 6`)

### Edge Cases

- Duplicate values (`[3,3]`) → check-before-insert handles it
- Exactly one valid answer is guaranteed → no missing-return worry

---

## Pattern Recognition

**Hash Map Complement Lookup** — when a problem asks "have I seen the number I need?", one pass with a value→index map beats nested loops.

---

## Approach

```
seen = {}
for index, num in enumerate(nums):
    complement = target - num
    if complement in seen:
        return [seen[complement], index]
    seen[num] = index
```

---

## Complexity

| Approach    | Time  | Space | Notes                    |
| ----------- | ----- | ----- | ------------------------ |
| Brute force | O(n²) | O(1)  | Check every pair         |
| Hash map    | O(n)  | O(n)  | One pass, complement map |
