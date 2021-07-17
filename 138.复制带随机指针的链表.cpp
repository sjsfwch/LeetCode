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
        unordered_map<Node*, Node*> tmp;
        auto p = head;
        while (p) {
            Node* cur = nullptr;
            if (tmp.find(p) != tmp.end())
                cur = tmp[p];
            else
                cur = new Node(p->val);
            tmp[p] = cur;
            auto nextp = p->next, randomp = p->random;
            if (nextp) {
                if (tmp.find(nextp) != tmp.end())
                    cur->next = tmp[nextp];
                else {
                    auto n = new Node(nextp->val);
                    tmp[nextp] = n;
                    cur->next = tmp[nextp];
                }
            } else
                cur->next = NULL;
            if (randomp) {
                if (tmp.find(randomp) == tmp.end()) {
                    auto n = new Node(randomp->val);
                    tmp[randomp] = n;
                }
                cur->random = tmp[randomp];
            } else
                cur->random = NULL;
            p = p->next;
        }
        return tmp[head];
    }
};
// @lc code=end
