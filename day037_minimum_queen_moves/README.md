# Day 037 - Minimum Queen Moves to Reach Target

| Field      | Details                  |
| :--------- | :----------------------- |
| Platform   | LeetCode (4061)          |
| Difficulty | Easy                     |
| Topic      | Arrays / Math            |
| Pattern    | Case Analysis (Geometry) |
| Time       | O(1)                     |
| Space      | O(1)                     |

---

## Problem Statement

There is an `8 x 8` empty chessboard with **1-indexed** rows and columns.

You are given `source = [sr, sc]`, the starting position of a queen, and `target = [tr, tc]`, the target position.

In one move, the queen travels one or more squares along a single **row**, **column**, or **diagonal**, staying within the board.

Return the minimum number of moves for the queen to land exactly on `target`.

---

## Input / Output

```
Input:  source = [8,1], target = [1,8]
Output: 1
Explanation: One diagonal move.

Input:  source = [4,2], target = [1,3]
Output: 2
Explanation: (4,2) → (4,3) → (1,3)

Input:  source = [1,1], target = [1,1]
Output: 0
```

---

## Constraints

```
source == [sr, sc]
target == [tr, tc]
1 ≤ sr, sc, tr, tc ≤ 8
```

---

## Understanding the Problem

The answer can only be **0, 1 or 2**:

- **0** → already on target
- **1** → same row, same column, or same diagonal (`|sr - tr| == |sc - tc|`)
- **2** → otherwise: move along the row to column `tc`, then along the column to row `tr`
  (a queen moves like a rook, and a rook reaches any square in ≤ 2 moves)

### Edge Cases

- Source equals target → 0
- Anti-diagonal (e.g. `(8,1)` → `(1,8)`) → still `|dr| == |dc|` → 1

---

## Pattern Recognition

**Case Analysis** — no BFS needed; the board geometry bounds the answer at 2.

---

## Approach

### Brute Force — BFS over 64 squares

```
BFS from source; neighbours = every square reachable in one queen move
Return distance to target
```

### Optimized — O(1)

```
if source == target:                         return 0
if sr == tr or sc == tc or |sr-tr| == |sc-tc|: return 1
return 2
```

---

## Complexity

| Approach      | Time  | Space | Notes                              |
| ------------- | ----- | ----- | ---------------------------------- |
| BFS           | O(64) | O(64) | Works for any board / obstacles    |
| Case Analysis | O(1)  | O(1)  | Empty board → answer is at most 2  |

---

## Online Compiler

https://onecompiler.com/
