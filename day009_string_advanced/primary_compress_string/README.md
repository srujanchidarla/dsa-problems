---
dayNumber: 9
title: "Compress String (Run-Length Encoding)"
platform: "Smart Interviews"
link: "https://hive.smartinterviews.in/contests/smart-interviews-basic/problems/compress-string"
difficulty: "Medium"
pattern: "Run-Length Encoding / Two Pointers"
approach: "Use a two-pointer approach (read pointer and write pointer) to count consecutive identical characters and replace the sequence with the character followed by the count."
optimized: "O(N)"
bruteforce: "O(N)"
space: "O(1)"
date: "2025-10-31"
commitHash: [INJECTED BY GITHUB ACTION]
tags:
  - string
  - two-pointers
  - encoding
---

# Compress String (Run-Length Encoding)

**Platform:** Smart Interviews | **Difficulty:** Medium | **Pattern:** Run-Length Encoding

---

## Problem Description

Given a string $S$ composed of repeating characters, compress it using **Run-Length Encoding (RLE)**. The compressed string should consist of each unique character followed by the count of its consecutive occurrences. (e.g., "AAABBC" becomes "A3B2C1").

## Approaches

### 1. Two-Pointer Run-Length Encoding (Optimal) - $O(N)$ ⭐

**Idea:** Use a single pass where one pointer (`read`) scans ahead to count the current run, and the result is constructed sequentially.

1. Initialize a `result` builder/string.
2. Use an outer loop index (`i`) to track the start of the current run.
3. Use an inner loop index (`j`) to find the end of the run (where $S[j]$ is different from $S[i]$).
4. Append $S[i]$ and the count $(j - i)$ to the result.
5. Set $i = j$ to start the next run.

**Time:** $O(N)$
**Space:** $O(N)$ (for the result string).

---
