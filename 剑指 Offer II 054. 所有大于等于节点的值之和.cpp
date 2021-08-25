#include "headers.h"

class Solution {
   public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        reInorder(root, sum);
        return root;
    }
    void reInorder(TreeNode* root, int& sum) {
        if (!root) return;
        reInorder(root->right, sum);
        root->val += sum;
        sum = root->val;
        reInorder(root->left, sum);
    }
};