# Day 071 - Is Subsequence

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (392)   |
| Difficulty | Easy             |
| Topic      | Strings          |
| Pattern    | Two Pointers     |
| Time       | O(n + m)         |
| Space      | O(1)             |

---

## Problem Statement

Given two strings `s` and `t`, return `true` if `s` is a subsequence of `t`, or `false` otherwise. A subsequence is a new string formed from the original by deleting some (or no) characters without changing the relative order of the remaining characters.

*Added 2026-11-05 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  s = "abc", t = "ahbgdc"
Output: true

Input:  s = "axc", t = "ahbgdc"
Output: false

Input:  s = "", t = "ahbgdc"
Output: true
```

---

## Pattern Recognition

**Two Pointers** — one pointer walks `s` (what you still need to find), the other walks `t` (where you are looking). Every time the characters match, advance both; otherwise advance only `t`. If the `s` pointer reaches the end, every character was found in order.

---

## Approach

### Brute Force — Re-Scan t From the Start for Every Character, O(n · m)

```
last = -1
for c in s:
    found = false
    for j in range(len(t)):           # naive: scan from 0 every time
        if j > last and t[j] == c:
            last = j
            found = true
            break
    if not found: return false
return true
```

Each character of `s` re-scans `t` from the beginning to find the next match after the last one — the same answer, but the repeated scanning is wasted work.

### Optimized — Two Pointers, One Pass, O(n + m)

```
i = 0   # pointer in s
for j in range(len(t)):
    if i < len(s) and s[i] == t[j]:
        i += 1
return i == len(s)
```

---

## Complexity

| Approach         | Time      | Space | Notes                          |
| ---------------- | --------- | ----- | ------------------------------ |
| Re-scan from start | O(n · m)  | O(1)  | Re-searches t per character    |
| Two pointers     | O(n + m)  | O(1)  | Each string walked once        |
