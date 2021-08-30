#include "headers.h"

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeSort(lists, 0, lists.size() - 1);
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int lo, int hi) {
        if (lo == hi)
            return lists[lo];
        else if (lo > hi)
            return nullptr;
        int mi = (lo + hi) >> 1;
        auto p = mergeSort(lists, lo, mi);
        auto q = mergeSort(lists, mi + 1, hi);
        return merge(p, q);
    }
    ListNode* merge(ListNode* p, ListNode* q) {
        if (!q) return p;
        if (!p) return q;
        ListNode* head = nullptr;
        if (p->val < q->val) {
            head = p;
            p = p->next;
        } else {
            head = q;
            q = q->next;
        }
        auto k = head;
        while (p || q) {
            if (p && q) {
                if (p->val < q->val) {
                    k->next = p;
                    p = p->next;
                } else {
                    k->next = q;
                    q = q->next;
                }
            } else if (p) {
                k->next = p;
                p = p->next;
            } else {
                k->next = q;
                q = q->next;
            }
            k = k->next;
        }
        return head;
    }
};