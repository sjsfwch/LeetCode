#include "headers.h"

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1), l2 = reverseList(l2);
        int c = 0, b = 0;
        auto phead = new ListNode(0);
        auto p = phead;
        while (l1 && l2) {
            b = (l1->val + l2->val + c) % 10;
            c = (l1->val + l2->val + c) / 10;
            p->next = new ListNode(b);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            b = (l1->val + c) % 10;
            c = (l1->val + c) / 10;
            p->next = new ListNode(b);
            p = p->next;
            l1 = l1->next;
        }
        while (l2) {
            b = (l2->val + c) % 10;
            c = (l2->val + c) / 10;
            p->next = new ListNode(b);
            p = p->next;
            l2 = l2->next;
        }
        if (c) {
            p->next = new ListNode(c);
        }
        phead = reverseList(phead->next);
        while (phead->val == 0 && phead->next) phead = phead->next;
        return phead;
    }
    ListNode* reverseList(ListNode* head) {
        shared_ptr<ListNode> phead(new ListNode());
        while (head) {
            auto tmp = head->next;
            head->next = phead->next;
            phead->next = head;
            head = tmp;
        }
        return phead->next;
    }
};