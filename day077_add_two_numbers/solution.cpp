#include <algorithm>
#include <string>
using namespace std;

// Definition for singly-linked list.
// struct ListNode { int val; ListNode* next; };

// Add two most-significant-first decimal strings.
string addDecimalStrings(string a, string b) {
    string res;
    int i = (int)a.size() - 1, j = (int)b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int d = carry;
        if (i >= 0) d += a[i--] - '0';
        if (j >= 0) d += b[j--] - '0';
        res.push_back(char('0' + d % 10));
        carry = d / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

class SolutionBruteForce {
    // O(n + m) time | O(n + m) space — convert both lists to numbers, add, rebuild.
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a, b;
        for (ListNode* n = l1; n; n = n->next) a.push_back(char('0' + n->val));
        for (ListNode* n = l2; n; n = n->next) b.push_back(char('0' + n->val));
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string sum = addDecimalStrings(a, b);
        ListNode dummy(0), *cur = &dummy;
        for (int i = (int)sum.size() - 1; i >= 0; --i) {
            cur->next = new ListNode(sum[i] - '0');
            cur = cur->next;
        }
        return dummy.next;
    }
};

class Solution {
    // O(max(n, m)) time | O(1) extra space — one pass, digit by digit, with a carry.
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int s = v1 + v2 + carry;
            carry = s / 10;
            cur->next = new ListNode(s % 10);
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy.next;
    }
};
