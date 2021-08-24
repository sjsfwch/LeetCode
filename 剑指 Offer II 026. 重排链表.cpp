#include "headers.h"

class Solution {
   public:
    void reorderList(ListNode* head) {
        int len = 0;
        auto p = head;
        while (p) {
            len++;
            p = p->next;
        }
        int count = (len + 1) / 2;
        p = head;
        while (count-- > 1) p = p->next;
        auto l2 = p->next, l1 = head;
        p->next = nullptr;
        l2 = reverseList(l2);
        while (l1 && l2) {
            auto l1next = l1->next, l2next = l2->next;
            l2->next = l1->next;
            l1->next = l2;
            l1 = l1next;
            l2 = l2next;
        }
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