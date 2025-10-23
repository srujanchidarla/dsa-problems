---
dayNumber: 1
title: Two Sum
platform: LeetCode
link: https://leetcode.com/problems/two-sum/
difficulty: Easy
date: 2025-10-23
commitHash: [TO BE FILLED BY GITHUB ACTION]
---

# 💡 Problem Statement

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

---

## 🛠️ Brute Force Approach (O(n²))

**Time Complexity:** O($n^2$)
**Space Complexity:** O(1)

The brute force approach uses a nested loop to check every possible pair of numbers.

## ⚡ Optimized Approach (O(n))

**Time Complexity:** O(n)
**Space Complexity:** O(n)

The optimized approach uses a **Hash Map (or Dictionary)** to store the numbers we've seen and their indices. For each number $x$ in `nums`, we check if `target - x` is already in the map. If it is, we've found the pair. If not, we add $x$ and its index to the map.
