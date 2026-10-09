# Day 048 - Valid Palindrome

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (125)   |
| Difficulty | Easy             |
| Topic      | Strings / Two Pointers |
| Pattern    | Two Pointers Inward |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

A phrase is a palindrome if, after converting all uppercase letters to lowercase and removing all non-alphanumeric characters, it reads the same forward and backward. Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.

*Imported 2026-10-09 from NeetCode auto-sync (reviewed, dead code removed).*

---

## Input / Output

```
Input:  s = "A man, a plan, a canal: Panama"
Output: true

Input:  s = "race a car"
Output: false
```

---

## Pattern Recognition

**Two Pointers Inward** — compare from both ends, skipping what doesn't count. No filtered copy needed.

---

## Approach

### Brute Force — Filter + Reverse, O(n) space

```
filtered = [c.lower() for c in s if c.isalnum()]
return filtered == filtered[::-1]
```

### Optimized — Two Pointers, O(1) space

```
i = 0, j = len(s) - 1
while i < j:
    skip non-alphanumeric at i / j
    if lower(s[i]) != lower(s[j]): return False
    i += 1; j -= 1
return True
```

---

## Complexity

| Approach     | Time | Space | Notes                          |
| ------------ | ---- | ----- | ------------------------------ |
| Filter+reverse | O(n) | O(n) | Builds a cleaned copy         |
| Two pointers | O(n) | O(1) | Compares in place, skips junk  |
