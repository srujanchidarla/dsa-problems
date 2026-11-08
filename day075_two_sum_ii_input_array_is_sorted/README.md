# Day 075 - Two Sum II - Input Array Is Sorted

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (167)   |
| Difficulty | Medium           |
| Topic      | Arrays / Two Pointers |
| Pattern    | Two Pointers on a Sorted Array |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

Given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order**, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return the indices of the two numbers, `index1` and `index2`, as an integer array `[index1, index2]` of length 2.

The tests are generated such that there is **exactly one solution**. You may not use the same element twice.

*Added 2026-11-08 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: numbers[1] + numbers[2] = 2 + 7 = 9.

Input:  numbers = [2,3,4], target = 6
Output: [1,3]

Input:  numbers = [-1,0], target = -1
Output: [1,2]
```

---

## Pattern Recognition

**Two pointers on a sorted array** — the classic reason sorted input changes the game. Put one pointer at each end: if the sum is too small, the only way to grow it is to move the left pointer right (everything to its left is even smaller); if the sum is too big, move the right pointer left. Each step rules out a whole row or column of pairs, which is why this is O(n) instead of the O(n^2) pair search — and O(1) space instead of the hash map Two Sum needs on unsorted input.

---

## Approach

### Brute Force — Check Every Pair, O(n^2)

```
for i in range(n):
    for j in range(i + 1, n):
        if numbers[i] + numbers[j] == target: return [i + 1, j + 1]
```

Ignores the sorted order entirely.

### Optimized — Two Pointers, O(n)

```
left = 0; right = n - 1
while left < right:
    total = numbers[left] + numbers[right]
    if total == target: return [left + 1, right + 1]
    elif total < target: left += 1      # need a bigger sum
    else: right -= 1                   # need a smaller sum
```

---

## Complexity

| Approach      | Time   | Space | Notes                                  |
| ------------- | ------ | ----- | -------------------------------------- |
| Check pairs   | O(n^2) | O(1)  | Ignores the sorted order               |
| Two pointers  | O(n)   | O(1)  | Sorted order rules out a pair per step |
