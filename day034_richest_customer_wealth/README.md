# Day 034 - Richest Customer Wealth

| Field      | Details                 |
| :--------- | :---------------------- |
| Platform   | LeetCode (1672)         |
| Difficulty | Easy                    |
| Topic      | Arrays / Matrix         |
| Pattern    | Row Sum + Running Max   |
| Time       | O(m × n)                |
| Space      | O(1)                    |

---

## Problem Statement

You are given an `m x n` integer grid `accounts` where `accounts[i][j]` is the amount of money the `i`th customer has in the `j`th bank.

Return the **wealth** that the richest customer has. A customer's wealth is the total amount of money they have in all their bank accounts.

---

## Input / Output

```
Input:  accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation: Both customers have wealth 6.

Input:  accounts = [[1,5],[7,3],[3,5]]
Output: 10

Input:  accounts = [[2,8,7],[7,1,3],[1,9,5]]
Output: 17
```

---

## Constraints

```
m == accounts.length
n == accounts[i].length
1 ≤ m, n ≤ 50
1 ≤ accounts[i][j] ≤ 100
```

---

## Understanding the Problem

- Each **row** is one customer → wealth = sum of that row
- Answer = **maximum** row sum

### Edge Cases

- Single customer → their row sum
- All customers equal → any row sum

---

## Pattern Recognition

**Row Sum + Running Max** — reduce each row to one number, then track the best seen so far.

---

## Approach

### Brute Force — O(m × n) time | O(m) space

```
Compute every row sum into a list
Return max(list)
```

### Optimized — O(m × n) time | O(1) space

```
best = 0
For each row:
    wealth = sum(row)
    best = max(best, wealth)
Return best
```

---

## Complexity

| Approach    | Time     | Space | Notes                          |
| ----------- | -------- | ----- | ------------------------------ |
| Brute Force | O(m × n) | O(m)  | Stores all row sums            |
| Optimized   | O(m × n) | O(1)  | Running max, no extra storage  |

---

## Online Compiler

https://onecompiler.com/
