---
dayNumber: 2
title: Sparse Arrays
platform: HackerRank
link: https://www.hackerrank.com/challenges/sparse-arrays/problem
difficulty: Easy
pattern: Hash Table, Frequency Counter
approach: Use a Hash Map to count input string frequencies in O(N), then lookup queries in O(1).
optimized: O(N + M)
bruteforce: O(N * M)
space: O(N)
date: 2025-10-24
commitHash: [INJECTED BY GITHUB ACTION]
---

# 💡 Problem Statement

Given a collection of input strings and a collection of query strings, for each query string, determine how many times it occurs in the list of input strings. Return an array of the results.

---

## 🔑 Key Pattern: Frequency Counter

The core task is to find the count of many different items within a large list. The **Brute Force** approach involves nested loops, which is slow. The **Frequency Counter** pattern (using a Hash Map/Dictionary) converts the $O(N \times M)$ search complexity into a single linear pass.

| Pattern Name          | Goal                                                                                                                                      | Optimization Strategy                                                                        |
| :-------------------- | :---------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------- |
| **Frequency Counter** | Count the occurrences of unique items in a list efficiently.                                                                              | **Pre-processing:** Spend $O(N)$ time to build a map of all unique strings and their counts. |
| **The Trick**         | Look up the count of a query string directly from the map in **O(1) time** instead of scanning the entire input list ($O(N)$) repeatedly. |

---

## 🛠️ Brute Force Approach (O(N $\times$ M))

**Approach:** Use nested loops. For each query, iterate through the entire list of input strings and increment a counter every time a match is found.

**Time Complexity:** $O(N \times M)$, where $N$ is the size of `stringList` and $M$ is the size of `queries`. This will timeout for large inputs.
**Space Complexity:** $O(1)$ (Excluding the output array)

---

## ⚡ Optimized Approach (O(N + M))

**Approach:** Use a Hash Map (Dictionary) to create a frequency count of all strings in `stringList`.

1.  **Build Map (O(N)):** Iterate through the `stringList` once. Store each unique string as a key and its count as the value in the hash map.
2.  **Query Lookup (O(M)):** Iterate through the `queries` array. For each query, check the hash map for its count in $O(1)$ average time. If the string exists, append its count to the result array; otherwise, append $0$.

**Time Complexity:** $O(N + M)$ (Time to build the map plus time to process all queries)
**Space Complexity:** $O(U)$, where $U$ is the number of unique strings in `stringList`.

---
