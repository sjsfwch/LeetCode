#include "headers.h"

struct cmp {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        while (head) {
            heap.push(head);
            head = head->next;
        }
        head = heap.top();
        heap.pop();
        auto p = head;
        while (!heap.empty()) {
            p->next = heap.top();
            p = heap.top();
            heap.pop();
        }
        p->next = nullptr;
        return head;
    }
};

int main() {
    auto n1 = new ListNode(-1);
    auto n2 = new ListNode(5);
    auto n3 = new ListNode(3);
    auto n4 = new ListNode(4);
    auto n5 = new ListNode(0);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Solution t;
    t.sortList(n1);
    return 0;
}