# Day 059 - Majority Element

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (169)   |
| Difficulty | Easy             |
| Topic      | Arrays / Voting  |
| Pattern    | Boyer-Moore Majority Vote |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

Given an array `nums` of size `n`, return the majority element — the element that appears more than `⌊n / 2⌋` times. You may assume the majority element always exists.

*Added 2026-10-30 from Srujan's LeetCode solved list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  nums = [3,2,3]
Output: 3

Input:  nums = [2,2,1,1,1,2,2]
Output: 2
```

---

## Pattern Recognition

**Boyer-Moore Majority Vote** — the majority element outnumbers all other elements combined. Pair each vote for a candidate against a vote for something else: the majority candidate is the only one that can survive the cancellations. A hash map also works, but costs O(n) extra space.

---

## Approach

### Brute Force — Count Each Element, O(n²)

```
for each x in nums:
    if nums.count(x) > n // 2: return x
```

### Optimized — Boyer-Moore Vote, O(n) time, O(1) space

```
candidate = ?, count = 0
for x in nums:
    if count == 0: candidate = x     # new leader
    count += 1 if x == candidate else -1
return candidate
```

Think of it as a tug-of-war: equal votes cancel, and the majority always has votes left over.

---

## Complexity

| Approach     | Time | Space | Notes                          |
| ------------ | ---- | ----- | ------------------------------ |
| Count each   | O(n²)| O(1)  | Re-counts everything           |
| Hash map     | O(n) | O(n)  | Simple, extra map              |
| Boyer-Moore  | O(n) | O(1)  | Cancel pairs, survivor wins    |
