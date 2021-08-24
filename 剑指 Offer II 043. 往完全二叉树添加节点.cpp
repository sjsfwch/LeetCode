/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include "headers.h"

class CBTInserter {
   private:
    vector<TreeNode*> tree;

   public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> tmp;
        tmp.push(root);
        while (!tmp.empty()) {
            auto node = tmp.front();
            tmp.pop();
            tree.push_back(node);
            if (node->left) tmp.push(node->left);
            if (node->right) tmp.push(node->right);
        }
    }

    int insert(int v) {
        auto node = new TreeNode(v);
        tree.push_back(node);
        int idx = tree.size();
        int parent = 0;
        if (idx % 2 == 1) {
            parent = (idx - 3) / 2;
            tree[parent]->right = node;
        } else {
            parent = (idx - 2) / 2;
            tree[parent]->left = node;
        }
        return tree[parent]->val;
    }

    TreeNode* get_root() {
        if (!tree.empty())
            return tree[0];
        else
            return nullptr;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */