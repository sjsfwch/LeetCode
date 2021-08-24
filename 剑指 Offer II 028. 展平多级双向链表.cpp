
// Definition for a Node.
class Node {
   public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

#include "headers.h"

class Solution {
   public:
    Node* flatten(Node* head) {
        if (!head) return head;
        flattenChild(head);
        return head;
    }
    Node* flattenChild(Node* head) {
        if (!head) return head;
        auto p = head, tail = head;
        while (p) {
            tail = p;
            auto next = p->next;
            if (p->child) {
                auto childTail = flattenChild(p->child);
                auto child = p->child;
                p->child = nullptr;
                childTail->next = p->next;
                if (p->next) p->next->prev = childTail;
                p->next = child;
                child->prev = p;
                tail = childTail;
            }
            p = next;
        }
        return tail;
    }
};

int main() {
    Solution t;
    auto node1 = new Node({1});
    auto node2 = new Node({2});
    auto node3 = new Node({3});
    node1->child = node2;
    node2->child = node3;
    t.flatten(node1);
    while (node1) {
        cout << node1->val << endl;
        node1 = node1->next;
    }
    return 0;
}