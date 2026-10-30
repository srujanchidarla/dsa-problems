# Day 058 - Plus One

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (66)    |
| Difficulty | Easy             |
| Topic      | Arrays / Math    |
| Pattern    | Scan from Right with Carry |
| Time       | O(n)             |
| Space      | O(1) extra       |

---

## Problem Statement

You are given a large integer represented as an array of digits, most significant first. Increment it by one and return the resulting array of digits.

*Added 2026-10-30 from Srujan's LeetCode solved list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  digits = [1,2,3]
Output: [1,2,4]

Input:  digits = [4,3,2,1]
Output: [4,3,2,2]

Input:  digits = [9]
Output: [1,0]

Input:  digits = [9,9]
Output: [1,0,0]
```

---

## Pattern Recognition

**Scan from Right with Carry** — adding 1 only ever touches the last digit, unless it is a 9. A 9 becomes 0 and the carry moves left; if every digit is 9, the answer needs one extra digit at the front.

---

## Approach

### Brute Force — Convert, Add, Convert Back, O(n)

```
number = int("".join(digits))   # whole number at once
number += 1
return [int(c) for c in str(number)]
```

Works for small inputs, but the whole point of the array form is that the number can be too big for a native integer — and it hides the carry idea.

### Optimized — Carry from the Right, O(n)

```
for i from n-1 down to 0:
    if digits[i] < 9:
        digits[i] += 1
        return digits           # carry stops here
    digits[i] = 0               # 9 + 1 = 0, carry on
return [1] + digits             # all 9s: 999 + 1 = 1000
```

---

## Complexity

| Approach        | Time | Space      | Notes                          |
| --------------- | ---- | ---------- | ------------------------------ |
| Convert to int  | O(n) | O(n)       | Overflows / hides the idea     |
| Carry from right| O(n) | O(1) extra | Only the all-9s case grows     |
