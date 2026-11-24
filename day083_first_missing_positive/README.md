# Day 083 - First Missing Positive

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (41)    |
| Difficulty | Hard             |
| Topic      | Arrays           |
| Pattern    | Cyclic Sort / In-Place Hashing |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

Given an unsorted integer array `nums`. Return the *smallest positive integer* that is *not present* in `nums`.

You must implement an algorithm that runs in `O(n)` time and uses `O(1)` auxiliary space.

""" + PROV + r"""

---

## Input / Output

```
Input:  nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Input:  nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Input:  nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
```

---

## Pattern Recognition

**Use the array as its own hash table** — the answer is always between 1 and `n + 1`, so every value that matters has a home slot: value `v` belongs at index `v - 1`. Swap each number into its home slot (ignoring negatives, zeros, and anything bigger than `n`), then the first slot whose number does not match its index is the missing positive.

---

## Approach

### Brute Force — Sort, Then Scan, O(n log n)

```
nums = sorted(nums)
want = 1
for v in nums:
    if v == want: want += 1
    elif v > want: break
return want
```

Simple and correct, but sorting costs O(n log n) — the problem demands O(n).

### Optimized — Cyclic Sort, O(n)

```
i = 0
while i < n:
    v = nums[i]
    if 1 <= v <= n and nums[v - 1] != v:
        nums[i], nums[v - 1] = nums[v - 1], nums[i]   # put v in its home slot
    else:
        i += 1
for i, v in enumerate(nums):
    if v != i + 1: return i + 1
return n + 1
```

Example: `[3,4,-1,1]` — swap 3 into slot 2 → `[-1,4,3,1]`, swap 4 into slot 3 → `[-1,1,3,4]`, swap 1 into slot 0 → `[1,-1,3,4]`. Slot 1 holds `-1` instead of `2`, so the answer is `2`.

---

## Complexity

| Approach          | Time      | Space | Notes                                        |
| ----------------- | --------- | ----- | -------------------------------------------- |
| Sort then scan    | O(n log n)| O(1)  | Simple, but sorting breaks the O(n) demand   |
| Cyclic sort       | O(n)      | O(1)  | Each swap puts one value home, at most n swaps |
