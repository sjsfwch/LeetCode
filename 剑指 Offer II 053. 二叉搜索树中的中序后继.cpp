#include "headers.h"

class Solution {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        auto cur = root;
        TreeNode* res = nullptr;
        while (cur) {
            if (cur->val > p->val) {
                res = cur;
                cur = cur->left;
            } else
                cur = cur->right;
        }
        return res;
    }
};