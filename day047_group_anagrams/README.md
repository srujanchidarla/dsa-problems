# Day 047 - Group Anagrams

| Field      | Details              |
| :--------- | :------------------- |
| Platform   | LeetCode (49)        |
| Difficulty | Medium               |
| Topic      | Strings / Hash Map   |
| Pattern    | Canonical Key Grouping |
| Time       | O(n · k log k)       |
| Space      | O(n · k)             |

---

## Problem Statement

Given an array of strings `strs`, group the anagrams together. Return the answer in any order.

*Imported 2026-10-09 from NeetCode auto-sync (reviewed).*

---

## Input / Output

```
Input:  strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

---

## Pattern Recognition

**Canonical Key Grouping** — anagrams share one canonical form (sorted letters). Map each word to its key; words with the same key belong together.

---

## Approach

### Brute Force — Pairwise Anagram Checks, O(n² · k log k)

```
for each word: compare against every existing group (is-anagram check)
```

### Optimized — Sorted-Key Hash Map, O(n · k log k)

```
map = {}
for w in strs:
    key = sorted(w)          # canonical form
    map[key].append(w)
return map.values()
```

---

## Complexity

| Approach     | Time          | Space    | Notes                          |
| ------------ | ------------- | -------- | ------------------------------ |
| Pairwise     | O(n²·k log k) | O(n·k)   | Re-checks every pair           |
| Sorted-key map | O(n·k log k)| O(n·k)   | One pass, canonical keys       |
