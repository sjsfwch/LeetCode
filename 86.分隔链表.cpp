/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        auto vHead = new ListNode(), pHead = new ListNode();
        pHead->next = head;
        auto p = head, pre_p = pHead, tail = vHead;
        while (p) {
            if (p->val < x) {
                pre_p->next = p->next;
                p->next = tail->next;
                tail->next = p;
                tail = tail->next;
                p = pre_p->next;
            } else {
                pre_p = p;
                p = p->next;
            }
        }
        tail->next = pHead->next;
        return vHead->next;
    }
};
// @lc code=end
int main() {
    auto n6 = new ListNode(2);
    auto n5 = new ListNode(5, n6);
    auto n4 = new ListNode(2, n5);
    auto n3 = new ListNode(3, n4);
    auto n2 = new ListNode(4, n3);
    auto n1 = new ListNode(1, n2);
    Solution t;
    t.partition(n1, 3);
    return 0;
}
