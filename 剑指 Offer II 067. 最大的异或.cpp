#include "headers.h"

class Trie {
    struct node {
        node* left = nullptr;   // 0
        node* right = nullptr;  // 1
    };

   private:
    node* _root;

   public:
    Trie() { _root = new node(); }
    void insert(int val) {
        auto p = _root;
        for (int i = 30; i >= 0; --i) {
            if ((val >> i) & 1) {
                if (!p->right) p->right = new node();
                p = p->right;
            } else {
                if (!p->left) p->left = new node();
                p = p->left;
            }
        }
    }
    int getMaxXOR(int val) {
        int res = 0;
        auto p = _root;
        for (int i = 30; i >= 0; --i) {
            if ((val >> i) & 1) {
                if (p->left) {
                    res += (1 << i);
                    p = p->left;
                } else
                    p = p->right;
            } else {
                if (p->right) {
                    res += (1 << i);
                    p = p->right;
                } else
                    p = p->left;
            }
        }
        return res;
    }
};

class Solution {
   public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for (auto& n : nums) t.insert(n);
        int res = 0;
        for (auto& n : nums) res = max(res, t.getMaxXOR(n));
        return res;
    }
};