# Day 077 - Add Two Numbers

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (2)     |
| Difficulty | Medium           |
| Topic      | Linked Lists     |
| Pattern    | Digit-by-Digit Addition with Carry |
| Time       | O(max(n, m))     |
| Space      | O(1) extra       |

---

## Problem Statement

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

""" + PROV + r"""

---

## Input / Output

```
Input:  l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input:  l1 = [0], l2 = [0]
Output: [0]

Input:  l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

---

## Pattern Recognition

**Add digit by digit with a carry** — the lists are already stored least-significant digit first, which is exactly the order you add in on paper. Walk both lists together, add the two digits plus whatever carried over, write the ones digit, and carry the tens digit forward. A dummy head node makes building the answer list painless, and the loop keeps going while either list still has digits or a carry remains.

---

## Approach

### Brute Force — Convert to Numbers, Add, Rebuild, O(n + m)

```
turn l1 into a number, turn l2 into a number, add them,
then build a new list from the sum's digits (reversed)
```

Simple, but it leans on big-integer arithmetic (Python `int`, Java `BigInteger`, or string addition in C++) and it throws away the structure the problem hands you.

### Optimized — One Pass with Carry, O(max(n, m))

```
dummy = ListNode(0); cur = dummy; carry = 0
while l1 or l2 or carry:
    v1 = l1.val if l1 else 0
    v2 = l2.val if l2 else 0
    s = v1 + v2 + carry
    carry = s // 10
    cur.next = ListNode(s % 10); cur = cur.next
    l1 = l1.next if l1 else None
    l2 = l2.next if l2 else None
return dummy.next
```

Example: `[2,4,3] + [5,6,4]` — 2+5=7, 4+6=10 (write 0, carry 1), 3+4+1=8 → `[7,0,8]`.

---

## Complexity

| Approach          | Time         | Space       | Notes                                        |
| ----------------- | ------------ | ----------- | -------------------------------------------- |
| Convert and add   | O(n + m)     | O(n + m)    | Needs big integers or string addition        |
| One pass, carry   | O(max(n, m)) | O(1) extra  | Walks each list once, carry does the work    |
