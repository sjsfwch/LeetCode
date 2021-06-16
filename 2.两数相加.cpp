/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= new ListNode(0);
        ListNode* phead=head;
        int carry=0,num1=0,num2=0,sum=0;
        while(l1||l2){
            num1= l1?l1->val:0;
            num2=l2?l2->val:0;
            if (l1) l1=l1->next;
            if (l2) l2=l2->next;
            sum=carry+num1+num2;
            carry=sum/10;
            sum=sum%10;;
            phead->next=new ListNode(sum);
            phead=phead->next;
        }
        if (carry>0) {;
            phead->next=new ListNode(carry);}
        return head->next;
    }
};
// @lc code=end

