#include "headers.h"

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto pa = headA, pb = headB;
        int lenA = 0, lenB = 0;
        while (pa) {
            pa = pa->next;
            lenA++;
        }
        while (pb) {
            pb = pb->next;
            lenB++;
        }
        pa = headA, pb = headB;
        while (lenA > lenB) {
            pa = pa->next;
            lenA--;
        }
        while (lenB > lenA) {
            pb = pb->next;
            lenB--;
        }
        while (pa && pb && pa != pb) {
            pa = pa->next;
            pb = pb->next;
        }
        return pa;
    }
};