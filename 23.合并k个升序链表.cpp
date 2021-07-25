/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
struct node {
    int val;
    ListNode* ptr;
    bool operator<(const node& node1) const { return val > node1.val; }
};
class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        priority_queue<node> tmp;
        for (auto n : lists) {
            if (n) tmp.push({n->val, n});
        }
        ListNode head, *tail = &head;
        while (!tmp.empty()) {
            auto cur = tmp.top();
            tmp.pop();
            tail->next = cur.ptr;
            tail = tail->next;
            if (cur.ptr->next) tmp.push({cur.ptr->next->val, cur.ptr->next});
        }
        return head.next;
    }
};
// @lc code=end
