#include "headers.h"

class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        auto p = head;
        while (p) {
            len++;
            p = p->next;
        }
        auto q = head;
        p = head;
        len = (len + 1) / 2;
        while (len-- > 0) q = q->next;
        q = reverseList(q);
        while (q && p) {
            if (q->val != p->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
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
