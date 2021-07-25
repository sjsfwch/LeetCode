/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        getMax(root, res);
        return res;
    }
    int getMax(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = 0, right = 0;
        left = getMax(root->left, res);
        right = getMax(root->right, res);
        res = max(left + right, res);
        return max(left, right) + 1;
    }
};
// @lc code=end
