/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include "headers.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto pa = headA, pb = headB;
        int countA = 0, countB = 0;
        while (pa) {
            countA++;
            pa = pa->next;
        }
        while (pb) {
            countB++;
            pb = pb->next;
        }

        if (countB == 0 || countA == 0) return nullptr;
        pa = headA, pb = headB;
        while (countA > countB) {
            pa = pa->next;
            countA--;
        }
        while (countB > countA) {
            pb = pb->next;
            countB--;
        }
        while (pa && pb) {
            if (pa == pb) return pa;
            pa = pa->next;
            pb = pb->next;
        }
        return nullptr;
    }
};
// @lc code=end
