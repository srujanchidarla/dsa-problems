# Day 082 - Intersection of Two Arrays

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (349)   |
| Difficulty | Easy             |
| Topic      | Arrays / Hash Set |
| Pattern    | Set Membership   |
| Time       | O(n + m)         |
| Space      | O(m)             |

---

## Problem Statement

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must be **unique** and you may return the result in **any order**.

""" + PROV + r"""

---

## Input / Output

```
Input:  nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Input:  nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
```

---

## Pattern Recognition

**Set membership** — the question is just "which values appear in both arrays?", and a hash set answers "is this value in the other array?" in O(1). Build the set once, then keep every `nums1` value that is in it, deduplicated.

---

## Approach

### Brute Force — Linear Scan for Each Value, O(n * m)

```
out = set()
for x in nums1:
    for y in nums2:
        if x == y: out.add(x)
return list(out)
```

Correct, but every value in `nums1` re-scans all of `nums2`.

### Optimized — Hash Set, O(n + m)

```
s2 = set(nums2)                    # everything in nums2, once
return list({x for x in nums1 if x in s2})
```

Example: `nums1 = [1,2,2,1]`, `nums2 = [2,2]` — the set is `{2}`, so only `2` survives, and the set comprehension drops the duplicate → `[2]`.

---

## Complexity

| Approach          | Time    | Space | Notes                                        |
| ----------------- | ------- | ----- | -------------------------------------------- |
| Linear scan each  | O(n * m)| O(n)  | Re-scans nums2 for every value              |
| Hash set          | O(n + m)| O(m)  | One lookup per value, duplicates dropped free |
