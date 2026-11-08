# Day 073 - Count Valid Substrings I

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode         |
| Difficulty | Medium           |
| Topic      | Strings / Sliding Window |
| Pattern    | Last Bad Position |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

You are given a string `s` consisting only of the characters `'a'`, `'b'`, and `'c'`.

A string is called **valid** if it does not contain `"abc"` as a **substring**.

Return the number of **valid substrings** in `s`. Substrings with different starting or ending indices are counted separately.

*Added 2026-11-08 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  s = "abac"
Output: 10
Explanation: No "abc" appears anywhere, so all 4*5/2 = 10 substrings count.

Input:  s = "abc"
Output: 5
Explanation: Only the whole string "abc" itself is invalid; the other 5 count.

Input:  s = "ac"
Output: 3
Explanation: All substrings are valid.
```

---

## Pattern Recognition

**Last bad position** — the only way a substring becomes invalid is by containing `"abc"`, and `"abc"` can only *end* at one place: the moment we see `s[r-2..r] == "abc"`. So for substrings ending at `r`, the earliest allowed start is just after the most recent `"abc"` that ends at or before `r`. Everything from that start to `r` is valid, and we add them all in one step — the same "count substrings ending here" trick as counting substrings without repeating characters.

---

## Approach

### Brute Force — Check Every Substring, O(n^2)

```
count = 0
for start in range(n):
    for end in range(start, n):
        if s[end-2..end] == "abc": break    # longer ones are invalid too
        count += 1
return count
```

Once `"abc"` shows up inside a substring, every longer substring starting at the same place is invalid as well, so the inner loop can stop early. Still quadratic in the worst case (e.g. `"aaaa..."` has no `"abc"` at all).

### Optimized — Sliding Left Boundary, O(n)

```
left = 0
ans = 0
for r in range(len(s)):
    if r >= 2 and s[r-2:r+1] == "abc":
        left = max(left, r - 1)   # substrings ending at r must start after r-2
    ans += r - left + 1           # every start from left..r is valid
return ans
```

`left` only moves forward, and each character is visited once.

---

## Complexity

| Approach              | Time   | Space | Notes                                   |
| --------------------- | ------ | ----- | --------------------------------------- |
| Check every substring | O(n^2) | O(1)  | Early break once "abc" appears          |
| Sliding left boundary | O(n)   | O(1)  | "abc" can only end at the current index |
