# Day 044 - Contains Duplicate

| Field      | Details             |
| :--------- | :------------------ |
| Platform   | LeetCode (217)      |
| Difficulty | Easy                |
| Topic      | Arrays / Hash Set   |
| Pattern    | Hash Set Membership |
| Time       | O(n)                |
| Space      | O(n)                |

---

## Problem Statement

Given an integer array `nums`, return `true` if any value appears at least twice in the array, and `false` if every element is distinct.

*Re-solved 2026-10-09 as Day 1 of the foundations rebuild.*

---

## Input / Output

```
Input:  nums = [1,2,3,1]
Output: true

Input:  nums = [1,2,3,4]
Output: false
```

---

## Understanding the Problem

- Same "have I seen this before?" instinct as Two Sum — but here we only need membership, not indices, so a **set** is enough
- `set()` (not `{}` — that's a dict) gives O(1) average membership checks
- Early return on the first repeat; `False` only after the full scan

### Edge Cases

- Empty or single-element array → `False`, loop simply never triggers
- Duplicate at the very end → still caught, just later

---

## Pattern Recognition

**Hash Set Membership** — the lighter sibling of the hash-map pattern: when you need "seen before?" without positions, a set is all you need.

---

## Approach

```
seen = set()
for num in nums:
    if num in seen:
        return True
    seen.add(num)
return False
```

---

## Complexity

| Approach | Time  | Space | Notes                        |
| -------- | ----- | ----- | ---------------------------- |
| Sort     | O(n log n) | O(1)/O(n) | Sort then scan neighbours |
| Hash set | O(n)  | O(n)  | One pass, early exit         |
