# Day 041 - Merge Strings Alternately

| Field      | Details                 |
| :--------- | :---------------------- |
| Platform   | LeetCode (1768)         |
| Difficulty | Easy                    |
| Topic      | Strings / Two Pointers  |
| Pattern    | Two Pointers (Zip)      |
| Time       | O(m + n)                |
| Space      | O(m + n)                |

---

## Problem Statement

You are given two strings `word1` and `word2`. Merge the strings by adding letters in **alternating order**, starting with `word1`. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

---

## Input / Output

```
Input:  word1 = "abc", word2 = "pqr"
Output: "apbqcr"

Input:  word1 = "ab", word2 = "pqrs"
Output: "apbqrs"

Input:  word1 = "abcd", word2 = "pq"
Output: "apbqcd"
```

---

## Constraints

```
1 ≤ word1.length, word2.length ≤ 100
word1 and word2 consist of lowercase English letters
```

---

## Understanding the Problem

- Take one char from `word1`, then one from `word2`, repeat
- When one runs out, append the rest of the other

### Edge Cases

- Equal lengths → perfect interleave
- One much longer → tail appended as-is

---

## Pattern Recognition

**Two Pointers (Zip)** — walk both strings with one index up to the longer length, appending whichever characters still exist.

---

## Approach

### Optimized — O(m + n)

```
result = ""
for i in 0..max(m, n)-1:
    if i < m: result += word1[i]
    if i < n: result += word2[i]
return result
```

---

## Complexity

| Approach     | Time     | Space    | Notes                          |
| ------------ | -------- | -------- | ------------------------------ |
| Two Pointers | O(m + n) | O(m + n) | Output string is the only cost |

---

## Online Compiler

https://onecompiler.com/
