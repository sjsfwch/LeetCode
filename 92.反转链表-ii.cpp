/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */
#include "headers.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        auto pHead = new ListNode(-1, head);
        auto pre_p = pHead, p = head;
        int count = 1;
        while (p && count < left) {
            pre_p = p;
            p = p->next;
            count++;
        }
        auto tail = p;
        while (p && count <= right) {
            auto next = p->next;
            p->next = pre_p->next;
            pre_p->next = p;
            count++;
            p = next;
        }
        tail->next = p;
        return pHead->next;
    }
};
// @lc code=end
