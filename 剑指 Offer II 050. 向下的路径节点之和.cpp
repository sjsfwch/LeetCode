#include "headers.h"

class Solution {
   public:
    int pathSum(TreeNode* root, int targetSum) {
        int path = 0;
        unordered_map<int, int> pre;
        pre[0] = 1;
        dfs(root, targetSum, pre, path, 0);
        return path;
    }
    void dfs(TreeNode* root, int target, unordered_map<int, int>& pre,
             int& path, int sum) {
        if (!root) return;
        sum += root->val;
        if (pre.find(sum - target) != pre.end()) path += pre[sum - target];
        pre[sum]++;
        dfs(root->left, target, pre, path, sum);
        dfs(root->right, target, pre, path, sum);
        pre[sum]--;
    }
};