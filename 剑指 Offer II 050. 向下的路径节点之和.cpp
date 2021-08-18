#include "headers.h"

class Solution {
   public:
    int pathSum(TreeNode* root, int targetSum) {
        int path = 0;
        dfs(root->left, targetSum, path, targetSum);
        dfs(root->right, targetSum, path, targetSum);
        dfs(root->left, targetSum - root->val, path, targetSum);
        dfs(root->right, targetSum - root->val, path, targetSum);
        return path;
    }
    void dfs(TreeNode* root, int target, int& path, int original) {
        if (!root) return;
        if (target == root->val) path++;
        dfs(root->left, original, path, original);
        dfs(root->right, original, path, original);
        dfs(root->left, target - root->val, path, original);
        dfs(root->right, target - root->val, path, original);
    }
};