# Day 050 - Reverse Linked List

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (206)   |
| Difficulty | Easy             |
| Topic      | Linked Lists     |
| Pattern    | Pointer Reversal |
| Time       | O(n)             |
| Space      | O(1)             |

---

## Problem Statement

Given the head of a singly linked list, reverse the list, and return the reversed list.

*Imported 2026-10-09 from NeetCode auto-sync (reviewed, variable names tidied).*

---

## Input / Output

```
Input:  head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

---

## Pattern Recognition

**Pointer Reversal** — walk once, flipping each `next` to point backward. Three pointers: previous, current, next.

---

## Approach

### Recursive — O(n) time, O(n) stack space

```
reverse(head):
    if head is None or head.next is None: return head
    new_head = reverse(head.next)
    head.next.next = head
    head.next = None
    return new_head
```

### Optimized — Iterative, O(n) time, O(1) space

```
prev, curr = None, head
while curr:
    nxt = curr.next
    curr.next = prev
    prev, curr = curr, nxt
return prev
```

---

## Complexity

| Approach  | Time | Space | Notes                          |
| --------- | ---- | ----- | ------------------------------ |
| Recursive | O(n) | O(n)  | Call stack holds the reversal  |
| Iterative | O(n) | O(1)  | Three pointers, one pass       |
