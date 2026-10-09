# Day 054 - Best Time to Buy and Sell Stock

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (121)   |
| Difficulty | Easy             |
| Topic      | Arrays / Greedy  |
| Pattern    | Track the Minimum |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

You are given an array `prices` where `prices[i]` is the price of a stock on day `i`. Choose one day to buy and a later day to sell for maximum profit. Return the maximum profit (0 if no profit is possible).

*Imported 2026-10-09 from NeetCode auto-sync (reviewed; `List` import added).*

---

## Input / Output

```
Input:  prices = [7,1,5,3,6,4]
Output: 5
Explanation: buy at 1, sell at 6 → profit 5
```

---

## Pattern Recognition

**Track the Minimum** — one pass: remember the cheapest price seen so far, and the best profit achievable by selling today.

---

## Approach

### Brute Force — All Pairs, O(n²)

```
best = 0
for buy in range(n):
    for sell in range(buy+1, n):
        best = max(best, prices[sell] - prices[buy])
```

### Optimized — Min Price + Best Profit, O(n)

```
l = 0  (buy pointer: cheapest day so far)
for r in range(1, n):
    if prices[r] > prices[l]: best = max(best, prices[r] - prices[l])
    else: l = r
```

---

## Complexity

| Approach   | Time  | Space | Notes                          |
| ---------- | ----- | ----- | ------------------------------ |
| All pairs  | O(n²) | O(1)  | Tries every buy/sell combo     |
| Min-track  | O(n)  | O(1)  | Cheapest-so-far + best profit  |
