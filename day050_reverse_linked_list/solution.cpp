// Definition for singly-linked list.
// struct ListNode { int val; ListNode* next; };

class SolutionRecursive {
    // O(n) time | O(n) space — recursion holds the reversal on the stack.
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

class Solution {
    // O(n) time | O(1) space — iterative pointer reversal.
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};
