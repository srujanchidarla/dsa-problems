# Day 046 - Valid Anagram

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (242)   |
| Difficulty | Easy             |
| Topic      | Strings / Hash Map |
| Pattern    | Frequency Counting |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise. An anagram uses the same characters the same number of times.

*Imported 2026-10-09 from NeetCode auto-sync (reviewed, scratch comments removed).*

---

## Input / Output

```
Input:  s = "anagram", t = "nagaram"
Output: true

Input:  s = "rat", t = "car"
Output: false
```

---

## Pattern Recognition

**Frequency Counting** — when order doesn't matter but counts do, count characters. One 26-slot array beats sorting.

---

## Approach

### Brute Force — Sort & Compare, O(n log n)

```
sort(s) == sort(t)
```

### Optimized — Single Frequency Array, O(n)

```
if lengths differ: return False
count[26] = 0
for c in s: count[c] += 1
for c in t: count[c] -= 1
return all zeros
```

---

## Complexity

| Approach       | Time      | Space | Notes                          |
| -------------- | --------- | ----- | ------------------------------ |
| Sort & compare | O(n log n)| O(n)  | Simple but slower              |
| Frequency array| O(n)      | O(1)  | Fixed 26 slots, one pass each  |
