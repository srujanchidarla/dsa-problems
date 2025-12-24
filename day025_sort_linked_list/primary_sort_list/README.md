---
dayNumber: 25
title: "Sort List (Merge Sort on Linked Lists)"
platform: "LeetCode"
link: "https://leetcode.com/problems/sort-list/"
difficulty: "Medium"
pattern: "Divide and Conquer / Slow & Fast Pointers"
approach: "Linked lists do not support random access, making Merge Sort the ideal choice. Use the 'Slow and Fast Pointers' technique to find the middle of the list, recursively split the list, and then merge the sorted halves."
optimized: "O(N log N)"
bruteforce: "O(N²)"
space: "O(log N) due to recursion stack"
date: "2025-11-22"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - linked-list
  - sorting
  - merge-sort
  - two-pointers
---

# Sort List (Merge Sort on Linked Lists)

**Platform:** LeetCode | **Difficulty:** Medium | **Pattern:** Divide and Conquer

---

## Problem Description

Given the `head` of a linked list, return the list after sorting it in ascending order. The solution should run in $O(n \log n)$ time and using constant extra space (excluding the recursion stack).

## Approaches

### 1. Merge Sort (Optimal) - $O(N \log N)$ ⭐

**Idea:** 1. **Find Middle:** Use a slow and fast pointer to find the middle node to split the list into two halves. 2. **Recursive Split:** Recursively call `sortList` on both halves. 3. **Merge:** Merge the two sorted linked lists using a dummy node and a tail pointer.

### 2. Bubble Sort / Insertion Sort (Brute Force) - $O(N^2)$

**Idea:** Repeatedly traverse the list to swap nodes or shift elements. This is highly inefficient for large lists.

---
