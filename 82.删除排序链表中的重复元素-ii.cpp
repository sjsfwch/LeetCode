/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */
#include "headers.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        auto p1 = new ListNode(-101), p2 = head, p3 = head;
        auto h = p1;
        int cur = -101, cur_count = 2;
        while (p3) {
            if (p3->val != cur) {
                // 链接
                if (cur_count == 1) {
                    p1->next = p2;
                    p1 = p1->next;
                }
                p2 = p3;
                cur = p3->val;
                cur_count = 1;
            } else
                cur_count++;
            p3 = p3->next;
        }
        if (cur_count == 1)
            p1->next = p2;
        else
            p1->next = nullptr;
        return h->next;
    }
};
// @lc code=end

int main() {
    Solution t;
    int a[7] = {1, 2, 3, 3, 4, 4, 5};
    ListNode head(1);
    auto p = &head;
    for (int i = 1; i < 7; i++) {
        ListNode tmp(a[i]);
        p->next = &tmp;
        p = p->next;
    }
    auto q = t.deleteDuplicates(&head);
    while (q) {
        cout << q->val << ' ';
    }
    return 0;
}