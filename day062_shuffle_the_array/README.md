# Day 062 - Shuffle the Array

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (1470)  |
| Difficulty | Easy             |
| Topic      | Arrays           |
| Pattern    | Interleave by Index |
| Time       | O(n)             |
| Space      | O(n)             |

---

## Problem Statement

Given the array `nums` consisting of `2n` elements in the form `[x1, x2, ..., xn, y1, y2, ..., yn]`, return the array in the form `[x1, y1, x2, y2, ..., xn, yn]`. In plain words: interleave the first half and the second half, one element from each in turn.

*Added 2026-10-30 from Srujan's LeetCode solved list (photo) — it was open as a browser tab in the photo but not previously in the repo.*

---

## Input / Output

```
Input:  nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7]

Input:  nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]

Input:  nums = [1,1,2,2], n = 2
Output: [1,2,1,2]
```

---

## Pattern Recognition

**Interleave by Index** — the answer has a fixed slot for every input element. The `i`-th element of the first half (`x`, at index `i`) goes to slot `2*i`; the `i`-th element of the second half (`y`, at index `n + i`) goes to slot `2*i + 1`. Once you see the slot formula, there is nothing left to search for.

---

## Approach

### Brute Force — Split, Then Zip, O(n)

```python
xs = nums[:n]          # [x1, x2, ..., xn]
ys = nums[n:]          # [y1, y2, ..., yn]
ans = []
for x, y in zip(xs, ys):
    ans.append(x)
    ans.append(y)
```

### Optimized — One Pass, Direct Slot Mapping, O(n)

```python
ans = [0] * (2 * n)
for i in range(n):
    ans[2 * i]     = nums[i]        # x_i
    ans[2 * i + 1] = nums[i + n]    # y_i
```

Same O(n) time, but no sliced copies of the two halves and no zip — each input element is written straight to its final slot.

---

## Complexity

| Approach       | Time | Space | Notes                          |
| -------------- | ---- | ----- | ------------------------------ |
| Split, then zip| O(n) | O(n)  | Two extra half-sized copies    |
| Direct slots   | O(n) | O(n)  | Output array is required       |
