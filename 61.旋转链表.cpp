/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */
#include "headers.h"
using namespace std;

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        auto p=head,end=head;
        int len=0;
        // 先获取链表长度
        while(p){
            end=p;
            p=p->next;
            len++;
        }
        
        // k取模
        k%=len;
        k=len-k;
        if(len<=1||k==len) return head;
        p=head;
        while(--k>0) p=p->next;
        auto new_head=p->next;
        end->next=head;
        p->next=nullptr;
        return new_head;
    }
};
// @lc code=end

int main(){
    Solution t;
    auto head=new ListNode(-1);
    auto p=head;
    for(int i=0;i<5;i++){
        p->next=new ListNode(i);
        p=p->next;
    }
    head=t.rotateRight(nullptr,0);
    while (head){
        cout<<head->val<<' ';
        auto p=head->next;
        delete head;
        head=p;
    }
    return 0;
}
