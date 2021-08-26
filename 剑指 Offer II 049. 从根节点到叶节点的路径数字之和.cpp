#include "headers.h"

class Solution {
   public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    void dfs(TreeNode* root, int base, int& sum) {
        if (root == nullptr) return;
        if((!root->left)&&(!root->right)){
            sum+=base+root->val;
            return;
        }
        base += root->val;
        base *= 10;
        dfs(root->left, base, sum);
        dfs(root->right, base, sum);
    }
};