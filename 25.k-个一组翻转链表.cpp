/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */
#include "headers.h"
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1) return head;
        ListNode* tmp=head;
        for(int i=0;i<k;i++){
            if(!tmp) return head;
            tmp=tmp->next;
        }

        ListNode* pre=reverseKGroup(tmp,k);

        // 翻转现有链表
        ListNode* cur=head;
        for (int i=0;i<k;i++){
            auto t=cur->next;
            cur->next=pre;
            pre=cur;
            cur=t;
        }
        return pre;
    }
};
// @lc code=end

