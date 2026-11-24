# Day 078 - Length of Last Word

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (58)    |
| Difficulty | Easy             |
| Topic      | Strings          |
| Pattern    | Scan from the End |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

Given a string `s` consisting of words and spaces, return *the length of the **last** word in the string.*

A **word** is a maximal substring consisting of non-space characters only.

""" + PROV + r"""

---

## Input / Output

```
Input:  s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Input:  s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Input:  s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
```

---

## Pattern Recognition

**Scan from the end** — you only care about the last word, so there is no reason to read the whole string from the front. Walk backwards past any trailing spaces, then count letters until you hit a space (or the start). The count is the answer, and you never stored a single word.

---

## Approach

### Brute Force — Split and Take the Last Word, O(n)

```
words = s.split()          # splits on spaces, drops the empties
return len(words[-1])
```

Short and correct, but `split()` builds a whole list of every word just to look at the last one.

### Optimized — Walk Backwards, O(n)

```
i = len(s) - 1
while i >= 0 and s[i] == ' ': i -= 1     # skip trailing spaces
length = 0
while i >= 0 and s[i] != ' ':            # count the last word
    length += 1
    i -= 1
return length
```

Example: `"   fly me   to   the moon  "` — skip the two trailing spaces, then count `m-o-o-n` (4) and stop at the space before `the`.

---

## Complexity

| Approach          | Time | Space | Notes                                        |
| ----------------- | ---- | ----- | -------------------------------------------- |
| Split the string  | O(n) | O(n)  | Builds a list of every word                  |
| Walk backwards    | O(n) | O(1)  | Reads only the tail of the string            |
