# Day 045 - Valid Parentheses

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (20)    |
| Difficulty | Easy             |
| Topic      | Strings / Stack  |
| Pattern    | Stack Matching   |
| Time       | O(n)             |
| Space      | O(n)             |

---

## Problem Statement

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

A string is valid when open brackets are closed by the same type of bracket, in the correct order, and every close has a matching open.

*Imported 2026-10-09 from NeetCode auto-sync (reviewed, debug prints removed).*

---

## Input / Output

```
Input:  s = "()[]{}"
Output: true

Input:  s = "(]"
Output: false
```

---

## Pattern Recognition

**Stack Matching** — openers get pushed, closers must match the top. The stack's LIFO order is exactly nesting order.

---

## Approach

### Brute Force — Repeated Pair Removal, O(n²)

```
while "()" or "{}" or "[]" in s: remove them
valid if s is empty at the end
```

### Optimized — Stack, O(n)

```
for c in s:
    if c is an opener: push
    else:
        if stack empty or top doesn't match c: return False
        pop
return stack is empty
```

---

## Complexity

| Approach     | Time  | Space | Notes                        |
| ------------ | ----- | ----- | ---------------------------- |
| Pair removal | O(n²) | O(n)  | Rescans the string each pass |
| Stack        | O(n)  | O(n)  | One pass, nesting = LIFO     |
