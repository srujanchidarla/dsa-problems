# Day 061 - Longest Common Prefix

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (14)    |
| Difficulty | Easy             |
| Topic      | Strings          |
| Pattern    | Vertical Scanning |
| Time       | O(S)             |
| Space      | O(1) extra       |

---

## Problem Statement

Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string `""`.

*Added 2026-10-30 from Srujan's LeetCode solved list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  strs = ["flower","flow","flight"]
Output: "fl"

Input:  strs = ["dog","racecar","car"]
Output: ""

Input:  strs = ["a"]
Output: "a"
```

---

## Pattern Recognition

**Vertical Scanning** — read one column (same index in every word) at a time. The first column where any word differs — or any word runs out — ends the prefix. The answer can never be longer than the shortest word.

---

## Approach

### Brute Force — Try Every Prefix, O(n · m²)

```
for length from len(shortest) down to 0:
    prefix = shortest[:length]
    if every word starts with prefix: return prefix
return ""
```

### Optimized — Vertical Scanning, O(S)

```
for i in range(len(strs[0])):
    c = strs[0][i]
    for w in strs[1:]:
        if i >= len(w) or w[i] != c:
            return strs[0][:i]     # first mismatch ends it
return strs[0]
```

(S = total characters in all strings.)

---

## Complexity

| Approach         | Time       | Space      | Notes                          |
| ---------------- | ---------- | ---------- | ------------------------------ |
| Try every prefix | O(n · m²)  | O(m)       | Re-checks whole prefixes       |
| Vertical scan    | O(S)       | O(1) extra | Stops at first mismatch        |
