#include "headers.h"

class Solution {
   public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> bst;
        inorder(root, bst);
        for (int i = 0; i < bst.size() - 1; ++i) {
            bst[i]->right = bst[i + 1];
            bst[i]->left = nullptr;
        }
        bst.back()->left = nullptr;
        bst.back()->right = nullptr;
        return bst[0];
    }
    void inorder(TreeNode* root, vector<TreeNode*>& bst) {
        if (!root) return;

        inorder(root->left, bst);
        bst.push_back(root);
        inorder(root->right, bst);
    }
};