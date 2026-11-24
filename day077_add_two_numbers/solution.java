import java.math.BigInteger;

// Definition for singly-linked list.
// class ListNode {
//     int val;
//     ListNode next;
// }

class SolutionBruteForce {
    // O(n + m) time | O(n + m) space — convert both lists to numbers, add, rebuild.
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        StringBuilder a = new StringBuilder(), b = new StringBuilder();
        for (ListNode n = l1; n != null; n = n.next) a.append(n.val);
        for (ListNode n = l2; n != null; n = n.next) b.append(n.val);
        BigInteger total = new BigInteger(a.reverse().toString())
                .add(new BigInteger(b.reverse().toString()));
        ListNode dummy = new ListNode(0), cur = dummy;
        for (char ch : new StringBuilder(total.toString()).reverse().toString().toCharArray()) {
            cur.next = new ListNode(ch - '0');
            cur = cur.next;
        }
        return dummy.next;
    }
}

class Solution {
    // O(max(n, m)) time | O(1) extra space — one pass, digit by digit, with a carry.
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0), cur = dummy;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            int v1 = l1 != null ? l1.val : 0;
            int v2 = l2 != null ? l2.val : 0;
            int s = v1 + v2 + carry;
            carry = s / 10;
            cur.next = new ListNode(s % 10);
            cur = cur.next;
            l1 = l1 != null ? l1.next : null;
            l2 = l2 != null ? l2.next : null;
        }
        return dummy.next;
    }
}
