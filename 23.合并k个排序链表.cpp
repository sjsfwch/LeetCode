/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* head=new ListNode(0);
        for(int i=0;i<lists.size();i++){
            head->next=merge(head->next,lists[i]);
        }
        return head->next;
    }
    ListNode* merge(ListNode* p1,ListNode* p2){
        if(!p1) return p2;
        if(!p2) return p1;
        if(p1->val <= p2->val){
            p1->next=merge(p1->next,p2);
            return p1;
        }
        else {
            p2->next=merge(p1,p2->next);
            return p2;
        }
    }
};
// @lc code=end

