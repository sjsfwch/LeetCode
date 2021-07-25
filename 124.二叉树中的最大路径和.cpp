/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include "headers.h"
// @lc code=start
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
class Solution {
   public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int res = INT32_MIN;
        getMax(root, res);
        return res;
    }
    int getMax(TreeNode* root, int& maxSum) {
        if (!root) return 0;
        int left, right, ret = 0;
        left = getMax(root->left, maxSum);
        right = getMax(root->right, maxSum);
        maxSum = max(maxSum, root->val + left + right);
        ret = max(left + root->val, right + root->val);
        ret = max(ret, root->val);
        maxSum = max(maxSum, ret);
        // printf("%d,%d,%d\n", left, right, maxSum);
        return ret;
    }
};
// @lc code=end
