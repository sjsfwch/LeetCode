#include "headers.h"

// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
   public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        auto insertP = search(head, insertVal);
        auto p = new Node(insertVal);
        p->next = insertP->next;
        insertP->next = p;
        return head;
    }

    Node* search(Node* head, int insertVal) {
        auto pre = head, cur = head, maxp = head;
        while (true) {
            pre = cur;
            cur = cur->next;
            if (maxp->val <= cur->val) maxp = cur;
            if (insertVal >= pre->val && insertVal <= cur->val) return pre;
            if (cur == head) break;
        }
        return maxp;
    }
};