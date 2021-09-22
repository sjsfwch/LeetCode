/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        auto p = head;
        while (p) {
            len++;
            p = p->next;
        }
        int base = len / k, more = len % k;
        vector<ListNode*> res(k, nullptr);
        int this_len = 0, cur = 0;
        p = head;
        auto pre = new ListNode();
        pre->next = p;
        while (p) {
            res[cur] = p;
            this_len++;
            int flag = more-- > 0 ? 1 : 0;
            while (this_len < base + flag) {
                pre = p;
                p = p->next;
                this_len++;
            }
            pre = p;
            p = p->next;
            pre->next = nullptr;
            cur++;
            this_len = 0;
        }
        // while (p) {
        //     res[cur] = p;
        //     this_len++;
        //     while (this_len < base) {
        //         pre = p;
        //         p = p->next;
        //         this_len++;
        //     }
        //     pre = p;
        //     p = p->next;
        //     pre->next = nullptr;
        //     cur++;
        //     this_len = 0;
        // }
        return res;
    }
};
// @lc code=end
