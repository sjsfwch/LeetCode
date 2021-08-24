#include "headers.h"

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto p = head, q = head;
        while (n-- > 1) p = p->next;
        while (p) {
            p = p->next;
            q = q->next;
        }
        auto tmp = q->next;
        if(tmp)
            q->next = tmp->next;
        else
            q->next=nullptr;
        return head;
    }
};