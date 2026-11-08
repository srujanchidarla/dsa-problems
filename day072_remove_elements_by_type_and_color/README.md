# Day 072 - Remove Elements by Type and Color

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (4103)  |
| Difficulty | Medium           |
| Topic      | Arrays / Stack   |
| Pattern    | Run Compression + Stack |
| Time       | O(n)             |
| Space      | O(n)             |

---

## Problem Statement

You are given three integer arrays `types`, `colors`, and `groupSize`, where `types` and `colors` have length `n`, and `groupSize` has length `m`.

- `types[i]` is the type of the element at index `i`.
- `colors[i]` is the color of the element at index `i`.
- `groupSize[t]` is the required number of elements in a removable group of type `t`.

In one operation, you may remove **exactly** `groupSize[t]` **consecutive** elements if all of them have type `t` and the **same color**. After each removal, the remaining elements become adjacent again while maintaining their relative order.

Return `true` if it is possible to remove all elements using a sequence of valid operations. Otherwise, return `false`.

*Added 2026-11-08 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  types = [0,1,1,0], colors = [5,3,3,5], groupSize = [2,2]
Output: true
Explanation: Remove indices 1-2 (type 1, color 3), the two 0s become
adjacent, then remove them too.

Input:  types = [0,1,0], colors = [9,9,9], groupSize = [3,2]
Output: false
Explanation: No consecutive group satisfies its required size.

Input:  types = [2,0,1,2], colors = [7,5,4,7], groupSize = [3,1,2]
Output: false
Explanation: Removing index 2 (type 1, groupSize 1) leaves [2,0,2],
and nothing else can be removed.
```

---

## Pattern Recognition

**Run compression + stack** — the same family as Remove All Adjacent Duplicates in String II. Squeeze consecutive elements with the same (type, color) into runs. A run that reaches its group's size vanishes, and its two neighbors become adjacent — they may now be the *same* run and merge. A stack holds the runs seen so far, so a removal only ever affects the top.

---

## Approach

### Brute Force — Rescan and Remove, Restarting Each Time, O(n^2)

```
while True:
    scan left to right for the first run of length >= groupSize[t]
    if none: return the array is empty
    delete exactly groupSize[t] elements from that run
    restart the scan from the beginning
```

Every deletion is an O(n) splice and there can be O(n) deletions, so this is quadratic — but it is a direct simulation of the rules.

### Optimized — One Pass With a Stack of Runs, O(n)

```
stack = []                       # each entry: [type, color, count]
for t, c in zip(types, colors):
    if stack top has (t, c): stack top count += 1
    else: push [t, c, 1]
    if stack top count == groupSize[t]: pop the run
return stack is empty
```

Removing a run can only glue its neighbors together, and the stack's top *is* the left neighbor — so the next element processed merges with it automatically. Each element is pushed and popped at most once.

---

## Complexity

| Approach            | Time   | Space | Notes                                  |
| ------------------- | ------ | ----- | -------------------------------------- |
| Rescan and remove   | O(n^2) | O(n)  | O(n) splice per deletion               |
| Stack of runs       | O(n)   | O(n)  | Each element pushed/popped at most once |
