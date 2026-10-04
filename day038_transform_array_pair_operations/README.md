# Day 038 - Transform Array Using Pair Operations

| Field      | Details                   |
| :--------- | :------------------------ |
| Platform   | LeetCode (4062)           |
| Difficulty | Medium                    |
| Topic      | Arrays / Brainteaser      |
| Pattern    | Invariant (Sum Preserved) |
| Time       | O(n)                      |
| Space      | O(1)                      |

---

## Problem Statement

You are given two integer arrays `source` and `target`.

In one operation, you may choose two distinct indices `i` and `j` in `source`, along with any integer `delta`. Then update:

```
source[i] = source[i] + source[j] - delta
source[j] = delta
```

Return `true` if it is possible to make `source` equal to `target` after any number of operations (including zero), otherwise `false`.

---

## Input / Output

```
Input:  source = [1,2,3], target = [0,2,4]
Output: true
Explanation: i = 0, j = 2, delta = 4 → [0, 2, 4]

Input:  source = [-5,-5], target = [-15,5]
Output: true

Input:  source = [1,2,1], target = [0,2,5]
Output: false
```

---

## Constraints

```
2 ≤ source.length == target.length ≤ 10^5
-10^9 ≤ source[i], target[i] ≤ 10^9
```

---

## Understanding the Problem

Look at what happens to `source[i] + source[j]`:

```
before: source[i] + source[j]
after:  (source[i] + source[j] - delta) + delta  =  source[i] + source[j]
```

→ Every operation **preserves the total sum**. So `sum(source) == sum(target)` is **necessary**.

It is also **sufficient** (n ≥ 2): use the last index as a "sink".
For every `j < n-1`, apply the operation with `i = n-1` and `delta = target[j]`.
Each `source[j]` becomes exactly `target[j]`, and the sink absorbs the difference —
since the sum never changes, the sink ends up equal to `target[n-1]`.

### Edge Cases

- Arrays already equal → true (zero operations)
- Values up to 10^9 × 10^5 → sums need **64-bit** integers

---

## Pattern Recognition

**Find the Invariant** — when an operation looks arbitrary, check what it can't change.
Here the only invariant is the sum, and it's the whole answer.

---

## Approach

### Optimized — O(n)

```
return sum(source) == sum(target)      (use 64-bit sums)
```

---

## Complexity

| Approach       | Time | Space | Notes                         |
| -------------- | ---- | ----- | ----------------------------- |
| Sum Invariant  | O(n) | O(1)  | Watch overflow — use long     |

---

## Online Compiler

https://onecompiler.com/
