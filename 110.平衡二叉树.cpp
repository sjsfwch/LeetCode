/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        auto res = getHeight(root);
        if (res < 0)
            return false;
        else
            return true;
    }
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int left = getHeight(root->left), right = getHeight(root->right);
        if (left < 0 || right < 0) return -1;
        if (abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};
// @lc code=end
