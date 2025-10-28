---
dayNumber: 1
title: Two Sum
platform: LeetCode
link: https://leetcode.com/problems/two-sum/
difficulty: Easy
pattern: Hash Table
approach: Use hash map to store complements for O(n) lookup
optimized: O(n)
bruteforce: O(n²)
space: O(n)
date: 2025-10-23
commitHash: [INJECTED BY GITHUB ACTION]
---

# 💡 Problem Statement

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

---

## 🔑 Key Pattern & Recognition

This problem is the canonical example of the **"Hash Map Complement"** pattern.

| Pattern Name            | Goal                                                                                                                                                          | How to Recognize                                                                                                                  |
| :---------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------ | :-------------------------------------------------------------------------------------------------------------------------------- |
| **Hash Map Complement** | Find two elements in an array/list that satisfy a specific condition (e.g., sum up to a target, difference equals K).                                         | The input is an unsorted array, and you need to find a **pair** whose relationship (sum, difference, etc.) equals a target value. |
| **The Trick**           | Convert the two-sum problem into a one-sum check. For every element $x$, instantly check if the required **complement** ($target - x$) has already been seen. |

This pattern allows you to solve two-pointer or two-value problems in **O(n) time** by sacrificing **O(n) space** for the hash map, which stores previously encountered values for $O(1)$ lookup.

---

## 🛠️ Brute Force Approach (O(n²))

**Approach:** Use nested loops. The outer loop selects the first number, and the inner loop checks every other number against it to find the pair that sums to the `target`.

**Time Complexity:** O($n^2$)
**Space Complexity:** O(1)

---

## ⚡ Optimized Approach (O(n))

**Approach:** We use the **Hash Map Complement** pattern. We iterate through the array only once, using a Hash Map (Dictionary) to track values we've already processed and their indices.

1.  **Iterate** through the array using index $i$ and value $x$.
2.  Calculate the **complement** needed: $C = target - x$.
3.  Check if $C$ is already a **key** in the Hash Map. If yes, we found our pair: return $\text{map}[C]$ and $i$.
4.  If not found, **add** the current number and its index to the map: $\text{map}[x] = i$.

**Time Complexity:** O(n) (Single pass with O(1) average lookup/insertion)
**Space Complexity:** O(n) (To store the Hash Map)
