# Day 053 - Longest Substring Without Repeating Characters

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (3)     |
| Difficulty | Medium           |
| Topic      | Strings / Sliding Window |
| Pattern    | Sliding Window + Set |
| Time       | O(n)             |
| Space      | O(min(n, alphabet)) |

---

## Problem Statement

Given a string `s`, find the length of the longest substring without repeating characters.

*Imported 2026-10-09 from NeetCode auto-sync (reviewed).*

---

## Input / Output

```
Input:  s = "abcabcbb"
Output: 3
Explanation: "abc" is the longest valid substring.

Input:  s = "pwwkew"
Output: 3
```

---

## Pattern Recognition

**Sliding Window + Set** — expand the right edge; when a duplicate appears, shrink from the left until it's gone. The set is the window's memory.

---

## Approach

### Brute Force — All Substrings, O(n²)

```
for each start: extend until a repeat, track max length
```

### Optimized — Sliding Window, O(n)

```
l = 0, window = set()
for r in range(n):
    while s[r] in window: remove s[l]; l += 1
    window.add(s[r])
    best = max(best, r - l + 1)
```

---

## Complexity

| Approach       | Time  | Space | Notes                          |
| -------------- | ----- | ----- | ------------------------------ |
| All substrings | O(n²) | O(n)  | Rebuilds every window          |
| Sliding window | O(n)  | O(n)  | Each char enters/leaves once   |
