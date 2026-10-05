# Day 039 - Longest Subarray Divisible by K with At Most One Negation I

| Field      | Details                           |
| :--------- | :-------------------------------- |
| Platform   | LeetCode (4063)                   |
| Difficulty | Medium                            |
| Topic      | Arrays / Hash Table / Prefix Sum  |
| Pattern    | Enumerate Subarrays + Modular Set |
| Time       | O(n²)                             |
| Space      | O(k)                              |

---

## Problem Statement

You are given an integer array `nums` and an integer `k`.

A subarray is **valid** if its sum is divisible by `k`, or can become divisible by `k` by **negating one element** within that subarray (replacing `x` with `-x`).

Return the length of the longest valid subarray. If no valid subarray exists, return `0`.

---

## Input / Output

```
Input:  nums = [4,1,2], k = 3
Output: 3
Explanation: Sum 7; negate 2 → 4 + 1 - 2 = 3, divisible by 3.

Input:  nums = [5,3,4], k = 7
Output: 2
Explanation: [3,4] sums to 7.

Input:  nums = [2,2,5], k = 6
Output: 2
Explanation: [2,2] → negate one → 0, divisible by 6.
```

---

## Constraints

```
1 ≤ nums.length ≤ 1000
-10^5 ≤ nums[i] ≤ 10^5
1 ≤ k ≤ 10^5
```

---

## Understanding the Problem

Negating `x` changes the sum from `S` to `S - 2x`. So a subarray is valid when:

```
S ≡ 0 (mod k)                                  — no negation
S - 2x ≡ 0 (mod k)  ⇔  2x ≡ S (mod k)          — for some x in the subarray
```

So for each subarray we need: is `S mod k` either `0` or in the set `{ 2x mod k : x in subarray }`?

### Edge Cases

- Negative numbers → normalise with `((v % k) + k) % k`
- `k = 1` → everything divisible → answer `n`
- No valid subarray → `0`

---

## Pattern Recognition

**Enumerate + Incremental State** — `n ≤ 1000` allows O(n²).
Fix the left end, extend right one step at a time, and update the running sum and the set of `2x mod k` in O(1) per step.

---

## Approach

### Brute Force — O(n³)

```
For every (l, r):
    S = sum(nums[l..r])
    valid if S % k == 0 or any (S - 2*nums[i]) % k == 0 for i in l..r
```

### Optimized — O(n²) time | O(k) space

```
seen = boolean array of size k   (reused across left ends)
for l in 0..n-1:
    S = 0
    for r in l..n-1:
        S += nums[r]
        seen[(2*nums[r]) mod k] = true
        if S mod k == 0 or seen[S mod k]:
            best = max(best, r - l + 1)
    clear only the entries set for this l   (keeps it O(n²), not O(n·k))
```

---

## Complexity

| Approach        | Time  | Space | Notes                                   |
| --------------- | ----- | ----- | --------------------------------------- |
| Brute Force     | O(n³) | O(1)  | Recheck every element per subarray      |
| Incremental Set | O(n²) | O(k)  | Running sum + set of 2x mod k           |

---

## Online Compiler

https://onecompiler.com/
