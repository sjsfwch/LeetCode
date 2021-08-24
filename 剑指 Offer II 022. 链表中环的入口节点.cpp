#include "headers.h"

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        auto fast = head, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if (!fast || !fast->next) return nullptr;
        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};