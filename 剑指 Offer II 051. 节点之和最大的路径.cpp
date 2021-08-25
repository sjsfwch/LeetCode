#include "headers.h"

class Solution {
   public:
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        dfs(root, maxSum);
        return maxSum;
    }

    int dfs(TreeNode* root, int& maxSum) {
        if (!root) return 0;
        int left = dfs(root->left, maxSum);
        int right = dfs(root->right, maxSum);
        maxSum = max(maxSum, root->val + left + right);
        maxSum = max(maxSum, root->val + left);
        maxSum = max(maxSum, root->val + right);
        maxSum = max(maxSum, root->val);
        return max(max(root->val + left, root->val + right), root->val);
    }
};