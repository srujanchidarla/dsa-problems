# Day 067 - Greatest Common Divisor of Strings

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (1071)  |
| Difficulty | Easy             |
| Topic      | Strings          |
| Pattern    | GCD / Repetition Check |
| Time       | O(n + m)         |
| Space      | O(n + m)         |

---

## Problem Statement

For two strings `s` and `t`, we say "`t` divides `s`" if `s` is made by repeating `t` one or more times. Given `str1` and `str2`, return the largest string `x` such that `x` divides both `str1` and `str2`. If no such string exists, return `""`.

*Added 2026-11-01 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Input:  str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Input:  str1 = "LEET", str2 = "CODE"
Output: ""
```

---

## Pattern Recognition

**GCD / Repetition Check** — if a string `x` divides both, then `str1 + str2` must equal `str2 + str1` (both are just `x` repeated). And the length of the answer must divide both lengths, so it is `gcd(len(str1), len(str2))`. That one check plus one gcd gives the whole answer.

---

## Approach

### Brute Force — Try Every Divisor Length, O(n · m)

```
for length from min(len(str1), len(str2)) down to 1:
    if len(str1) % length == 0 and len(str2) % length == 0:
        candidate = str1[:length]
        if str1 == candidate * (len(str1) // length) and str2 == candidate * (len(str2) // length):
            return candidate
return ""
```

### Optimized — Concatenation Check + GCD, O(n + m)

```
if str1 + str2 != str2 + str1: return ""
g = gcd(len(str1), len(str2))
return str1[:g]
```

Why it works: equal concatenations mean both strings are built from the same repeating unit, and the gcd length is the longest unit that fits both.

---

## Complexity

| Approach         | Time      | Space      | Notes                          |
| ---------------- | --------- | ---------- | ------------------------------ |
| Try every length | O(n · m)  | O(n + m)   | Rebuilds each candidate string |
| Concat + GCD     | O(n + m)  | O(n + m)   | One check, one gcd             |
