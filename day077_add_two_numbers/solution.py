from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class SolutionBruteForce:
    """O(n + m) time | O(n + m) space — convert both lists to numbers, add, rebuild."""

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        a, b = [], []
        while l1:
            a.append(str(l1.val))
            l1 = l1.next
        while l2:
            b.append(str(l2.val))
            l2 = l2.next
        total = int("".join(reversed(a))) + int("".join(reversed(b)))
        dummy = ListNode(0)
        cur = dummy
        for ch in reversed(str(total)):
            cur.next = ListNode(int(ch))
            cur = cur.next
        return dummy.next


class Solution:
    """O(max(n, m)) time | O(1) extra space — one pass, digit by digit, with a carry."""

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        cur = dummy
        carry = 0
        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            s = v1 + v2 + carry
            carry = s // 10
            cur.next = ListNode(s % 10)
            cur = cur.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return dummy.next
