#include "headers.h"

class Solution {
   public:
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