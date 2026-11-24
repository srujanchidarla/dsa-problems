# Day 080 - Reverse String

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (344)   |
| Difficulty | Easy             |
| Topic      | Strings / Two Pointers |
| Pattern    | Swap from Both Ends |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array **in-place** with `O(1)` extra memory.

""" + PROV + r"""

---

## Input / Output

```
Input:  s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Input:  s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

---

## Pattern Recognition

**Two pointers from both ends** — the first character belongs last and the last belongs first, so swap them and walk inward. When the pointers meet, the string is reversed, and you never needed a second array.

---

## Approach

### Brute Force — Build a Reversed Copy, O(n)

```
rev = s[::-1]        # a brand-new reversed list
s[:] = rev           # copy it back
```

Works, but it spends O(n) extra memory — exactly what the problem forbids.

### Optimized — Swap In Place, O(n)

```
left, right = 0, len(s) - 1
while left < right:
    s[left], s[right] = s[right], s[left]
    left += 1
    right -= 1
```

Example: `["h","e","l","l","o"]` — swap `h`/`o`, then `e`/`l`, and the middle `l` stays put → `["o","l","l","e","h"]`.

---

## Complexity

| Approach          | Time | Space | Notes                                        |
| ----------------- | ---- | ----- | -------------------------------------------- |
| Reversed copy     | O(n) | O(n)  | Extra array, breaks the O(1) requirement     |
| Swap in place     | O(n) | O(1)  | Two pointers, each character moved once      |
