# Day 055 - Kids With the Greatest Number of Candies

| Field      | Details                 |
| :--------- | :---------------------- |
| Platform   | LeetCode (1431)         |
| Difficulty | Easy                    |
| Topic      | Arrays                  |
| Pattern    | Precompute Max + Scan   |
| Time       | O(n)                    |
| Space      | O(1)                    |

---

## Problem Statement

There are `n` kids with candies. You are given an integer array `candies`, where `candies[i]` is the number of candies the `i`th kid has, and an integer `extraCandies`.

Return a boolean array `result` of length `n`, where `result[i]` is `true` if, after giving the `i`th kid all the `extraCandies`, they will have the **greatest** number of candies among all the kids, or `false` otherwise.

Multiple kids can have the greatest number of candies.

---

## Input / Output

```
Input:  candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]

Input:  candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false]

Input:  candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
```

---

## Constraints

```
n == candies.length
2 ≤ n ≤ 100
1 ≤ candies[i] ≤ 100
1 ≤ extraCandies ≤ 50
```

---

## Understanding the Problem

- Giving extras to kid `i` doesn't change anyone else → the bar to beat is the **current max**
- Kid `i` qualifies iff `candies[i] + extraCandies >= max(candies)` (ties count)

### Edge Cases

- Ties for greatest → `>=`, not `>`
- The kid who already has the max is always `true`

---

## Pattern Recognition

**Precompute + Scan** — compute the max once instead of re-scanning for every kid.

---

## Approach

### Brute Force — O(n²)

```
For each kid i:
    check candies[i] + extra >= candies[j] for every j
```

### Optimized — O(n)

```
mx = max(candies)
result[i] = candies[i] + extra >= mx
```

---

## Complexity

| Approach    | Time  | Space | Notes                         |
| ----------- | ----- | ----- | ----------------------------- |
| Brute Force | O(n²) | O(1)  | Re-scan all kids per kid      |
| Optimized   | O(n)  | O(1)  | Max once (output not counted) |

---

## Online Compiler

https://onecompiler.com/
