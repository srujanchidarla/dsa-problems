# Day 081 - Remove All Adjacent Duplicates In String

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (1047)  |
| Difficulty | Easy             |
| Topic      | Strings / Stack  |
| Pattern    | Stack Cancels Pairs |
| Time       | O(n)             |
| Space      | O(n)             |

---

## Problem Statement

You are given a string `s` consisting of lowercase English letters. A **duplicate removal** consists of choosing two **adjacent** and **equal** letters and removing them.

We repeatedly make **duplicate removals** on `s` until we no longer can.

Return *the final string after all such duplicate removals have been made*. It can be proven that the answer is **unique**.

""" + PROV + r"""

---

## Input / Output

```
Input:  s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Input:  s = "azxxzy"
Output: "ay"
```

---

## Pattern Recognition

**A stack cancels pairs** — removing a pair can bring two previously-separated letters together and make a new pair, so the only thing that matters is the last surviving letter. Keep a stack of survivors: if the next letter matches the top, both vanish; otherwise push it. One pass, no rescans.

---

## Approach

### Brute Force — Rescan Until Stable, O(n^2)

```
changed = True
while changed:
    changed = False
    scan s, delete every adjacent equal pair in one pass
    if any pair was deleted: changed = True
```

Correct, but each pass can delete only the pairs visible right now, and a deletion can create a new pair — so the string may need many passes.

### Optimized — Stack, O(n)

```
stack = []
for ch in s:
    if stack and stack[-1] == ch:
        stack.pop()          # pair cancels
    else:
        stack.append(ch)
return ''.join(stack)
```

Example: `"abbaca"` — push `a`, `b`; next `b` matches the top, pop it; next `a` matches the new top `a`, pop it; push `c`, `a` → `"ca"`.

---

## Complexity

| Approach          | Time  | Space | Notes                                        |
| ----------------- | ----- | ----- | -------------------------------------------- |
| Rescan until stable | O(n^2) | O(n) | Each deletion can force another full pass    |
| Stack             | O(n)  | O(n)  | One pass; the top of the stack is all history |
