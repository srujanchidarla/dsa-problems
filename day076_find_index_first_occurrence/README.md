# Day 076 - Find the Index of the First Occurrence in a String

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (28)    |
| Difficulty | Easy             |
| Topic      | Strings / String Matching |
| Pattern    | KMP (Prefix Function) |
| Time       | O(n + m)         |
| Space      | O(m)             |

---

## Problem Statement

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

*Added 2026-11-10 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Input:  haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```

---

## Pattern Recognition

**KMP (Knuth-Morris-Pratt)** — the brute force re-checks characters it already matched every time a comparison fails (think `"aaaaab"` vs `"aaab"`: it restarts from scratch at every `a`). KMP's insight is that the *needle itself* tells you how far to jump: precompute, for every prefix of the needle, the longest proper prefix that is also a suffix (the LPS / prefix-function array). After a mismatch, the part of the needle you already matched has a known overlap with itself, so you slide the needle forward by exactly that overlap instead of starting over. Each character of the haystack is examined once.

---

## Approach

### Brute Force — Try Every Start, Compare Char by Char, O(n * m)

```
for i in range(len(haystack) - len(needle) + 1):
    if haystack[i:i+len(needle)] == needle: return i
return -1
```

Simple and correct, but a mismatch near the end of the needle throws away all the matching work and restarts at `i + 1`.

### Optimized — KMP, O(n + m)

```
lps = prefix function of needle     # lps[k] = longest proper prefix of
                                    # needle[0..k] that is also a suffix
j = 0                               # how much of needle is matched
for i in range(len(haystack)):
    while j > 0 and haystack[i] != needle[j]:
        j = lps[j - 1]              # slide needle forward, keep the overlap
    if haystack[i] == needle[j]: j += 1
    if j == len(needle): return i - j + 1
return -1
```

Example of the LPS idea: for needle `"aabaa"`, `lps = [0, 1, 0, 1, 2]` — the prefix `"aa"` reappears as a suffix, so after matching `"aabaa"` partially you know where to resume.

---

## Complexity

| Approach          | Time     | Space | Notes                                        |
| ----------------- | -------- | ----- | -------------------------------------------- |
| Try every start   | O(n * m) | O(1)  | Re-checks matched characters after a mismatch |
| KMP               | O(n + m) | O(m)  | LPS table lets each character be read once   |
