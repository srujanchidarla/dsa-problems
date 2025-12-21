---
dayNumber: 22
title: "Counting Sort (Implementation)"
platform: "Custom"
link: "https://www.geeksforgeeks.org/counting-sort/"
difficulty: "Medium"
pattern: "Non-Comparison Sorting / Frequency Mapping"
approach: "Count the occurrences of each unique element in the input. Use these counts to determine the position of each element in the output array. This effectively bypasses the O(N log N) limit of comparison sorts."
optimized: "O(N + K)"
bruteforce: "O(N log N)"
space: "O(N + K)"
date: "2025-11-19"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - sorting
  - linear-time
  - non-comparison
---

# Counting Sort (Implementation)

**Platform:** Custom | **Difficulty:** Medium | **Pattern:** Frequency Mapping

---

## Problem Description

Given an array of integers where the range of values is known and relatively small, sort the array using the **Counting Sort** algorithm.

## Approaches

### 1. Frequency Array Mapping (Optimal) - $O(N + K)$ ⭐

**Idea:** Counting sort works by:

1. Finding the maximum element in the array to define the range $K$.
2. Creating a frequency (count) array of size $K+1$.
3. Storing the count of each element.
4. (Optional for stability) Modifying the count array to store the cumulative sum of counts.
5. Placing elements into a new output array based on their cumulative counts and decrementing the count.

**Constraints:** \* This algorithm is highly efficient only when $K$ (the range of elements) is not significantly larger than $N$ (the number of elements).

- Traditional implementation handles only non-negative integers (though it can be adapted for negatives by using an offset).

---
