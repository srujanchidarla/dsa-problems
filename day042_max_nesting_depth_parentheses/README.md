# Day 042 - Maximum Nesting Depth of the Parentheses

| Field      | Details                  |
| :--------- | :----------------------- |
| Platform   | LeetCode (1614)          |
| Difficulty | Easy                     |
| Topic      | Strings / Stack          |
| Pattern    | Counter as Implicit Stack |
| Time       | O(n)                     |
| Space      | O(1)                     |

---

## Problem Statement

Given a **valid parentheses string** `s`, return the **nesting depth** of `s` — the maximum number of nested parentheses.

---

## Input / Output

```
Input:  s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside 3 nested parentheses.

Input:  s = "(1)+((2))+(((3)))"
Output: 3

Input:  s = "()(())((()()))"
Output: 3
```

---

## Constraints

```
1 ≤ s.length ≤ 100
s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'
It is guaranteed that s is a valid parentheses string
```

---

## Understanding the Problem

- `(` → go one level deeper
- `)` → come back up one level
- Answer = deepest level ever reached
- Other characters don't matter

### Edge Cases

- No parentheses → 0
- Input is guaranteed valid → no need to check for unmatched `)`

---

## Pattern Recognition

**Counter as Implicit Stack** — with only one bracket type, a stack only ever needs its **size**, so a single integer replaces it.

---

## Approach

### Brute Force — Explicit Stack, O(n) space

```
push on '(', pop on ')', track max stack size
```

### Optimized — Counter, O(1) space

```
depth = 0, best = 0
for c in s:
    if c == '(': depth++, best = max(best, depth)
    if c == ')': depth--
return best
```

---

## Complexity

| Approach       | Time | Space | Notes                          |
| -------------- | ---- | ----- | ------------------------------ |
| Explicit Stack | O(n) | O(n)  | Generalises to multiple types  |
| Counter        | O(n) | O(1)  | One bracket type → just count  |

---

## Online Compiler

https://onecompiler.com/
