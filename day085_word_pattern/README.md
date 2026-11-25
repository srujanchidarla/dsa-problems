# Day 085 - Word Pattern

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (290)   |
| Difficulty | Easy             |
| Topic      | Strings / Hash Map |
| Pattern    | Bijection with Two Maps |
| Time       | O(n)             |
| Space      | O(n)             |

---

## Problem Statement

Given a `pattern` and a string `s`, find if `s` follows the same pattern.

Here **follow** means a full match, such that there is a bijection between a letter in `pattern` and a **non-empty** word in `s`. Specifically:

- Each letter in `pattern` maps to **exactly** one unique word in `s`.
- Each unique word in `s` maps to **exactly** one letter in `pattern`.
- No two letters map to the same word, and no two words map to the same letter.

*Added 2026-11-25 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation:
The bijection can be established as:
- 'a' maps to "dog".
- 'b' maps to "cat".

Input:  pattern = "abba", s = "dog cat cat fish"
Output: false

Input:  pattern = "aaaa", s = "dog cat cat dog"
Output: false
```

---

## Pattern Recognition

**Bijection needs two maps** — one direction is not enough. Checking only "each letter maps to one word" would let `a` and `b` both map to `"dog"`, which is not a bijection. Keep a letter→word map *and* a word→letter map, and fail the moment either one disagrees.

---

## Approach

### Brute Force — Compare Every Pair, O(n^2)

```
words = s.split()
if len(pattern) != len(words): return False
for i in range(n):
    for j in range(n):
        if (pattern[i] == pattern[j]) != (words[i] == words[j]):
            return False
return True
```

Two positions must agree on both sides: same letter exactly when same word. Correct, but every pair gets checked.

### Optimized — Two Hash Maps, O(n)

```
words = s.split()
if len(pattern) != len(words): return False
p2w, w2p = {}, {}
for ch, w in zip(pattern, words):
    if ch in p2w and p2w[ch] != w: return False
    if w in w2p and w2p[w] != ch: return False
    p2w[ch] = w
    w2p[w] = ch
return True
```

Example: `"abba"` / `"dog cat cat dog"` — `a→dog`, `b→cat`, second `b` meets `cat` again, last `a` meets `dog` again → `true`. But `"aaaa"` / `"dog cat cat dog"` fails at the second word: `a` already maps to `dog`, not `cat`.

---

## Complexity

| Approach          | Time  | Space | Notes                                        |
| ----------------- | ----- | ----- | -------------------------------------------- |
| Compare all pairs | O(n^2)| O(1)  | Every position checked against every other   |
| Two hash maps     | O(n)  | O(n)  | One pass; both directions enforced           |
