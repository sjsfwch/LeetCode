/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p=head,*q=head;
        while(n-->0) q=q->next;
        if(!q){
            head=head->next;
            return head;
        }
        while(q->next){
            p=p->next;
            q=q->next;
        }
        p->next=p->next->next;
        return head;
    }
};
// @lc code=end

