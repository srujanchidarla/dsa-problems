---
dayNumber: 9
title: "Reverse Words in a String"
platform: "LeetCode"
link: "https://leetcode.com/problems/reverse-words-in-a-string/"
difficulty: "Medium"
pattern: "Word Traversal / Stack / Two Pointers"
approach: "Split the string into words, then process the list of words in reverse order, ignoring extra spaces. Or, use two pointers to reverse each word in-place, then reverse the entire string."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(N)"
date: "2025-10-31"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - string
  - stack
  - two-pointers
  - array
---

# Reverse Words in a String

**Platform:** LeetCode | **Difficulty:** Medium | **Pattern:** Word Traversal

---

## Problem Description

Given an input string $S$, reverse the order of the words. Words are separated by at least one space. The output should not contain leading, trailing, or multiple spaces between words.

**Example:**
Input: "the sky is blue"
Output: "blue is sky the"

## Approaches

### 1. Split, Filter, and Reverse (Optimal/Practical) - $O(N)$ ⭐

**Idea:** This is the most practical and clean $O(N)$ solution in most languages.

1.  Use the language's built-in function to **split** the string by spaces.
2.  **Filter** the resulting array/list to remove any empty strings (which result from multiple spaces).
3.  **Reverse** the order of the word list.
4.  **Join** the list back into a single string using a single space.

**Time:** $O(N)$ (Splitting, reversing, and joining are linear)
**Space:** $O(N)$ (To store the list of words).

### 2. Two-Pointer In-Place Reversal (Advanced) - $O(N)$

**Idea:** A more memory-efficient solution (if the language allows in-place modification of the string/char array). First, reverse every word individually. Second, reverse the entire resulting string. This requires careful handling of spaces and ensures $O(1)$ extra space usage.

---
