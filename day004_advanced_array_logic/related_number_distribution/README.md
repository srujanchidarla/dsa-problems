---
dayNumber: 4
title: "Number Distribution (Frequency Count)"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/number-distribution"
difficulty: "Easy"
pattern: "Frequency Counting / Hashing"
approach: "Use a hash map to count the occurrences of each number. Then, iterate through the map to find the counts of required numbers."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(N)"
date: "2025-10-26"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - array
  - hashing
  - frequency
---

# Number Distribution (Frequency Count)

**Platform:** Smart Interviews | **Difficulty:** Easy | **Pattern:** Frequency Counting

---

## Problem Description

Given an array of integers, count and print the frequency (number of occurrences) of each distinct element in the array.

---

## Approaches

### 1. Hashing/Frequency Map (Optimal) - $O(N)$ ⭐

**Idea:** Using a hash map (dictionary in Python) allows us to count frequencies in a single $O(N)$ pass, with $O(K)$ space where $K$ is the number of distinct elements ($K \le N$).

1.  Initialize an empty hash map.
2.  Iterate through the array: for each element, increment its count in the hash map.
3.  Iterate through the hash map (or original array again) to print the results.

**Time:** $O(N)$
**Space:** $O(N)$

---
