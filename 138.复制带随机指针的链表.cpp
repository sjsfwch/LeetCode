/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */
#include "headers.h"
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=start

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old2new;
        auto p = head;
        while (p) {
            if (old2new.find(p) == old2new.end()) old2new[p] = new Node(p->val);
            if (p->next) {
                if (old2new.find(p->next) == old2new.end())
                    old2new[p->next] = new Node(p->next->val);
                old2new[p]->next = old2new[p->next];
            }
            if (p->random) {
                if (old2new.find(p->random) == old2new.end())
                    old2new[p->random] = new Node(p->random->val);
                old2new[p]->random = old2new[p->random];
            }
            p = p->next;
        }
        return old2new[head];
    }
};
// @lc code=end
