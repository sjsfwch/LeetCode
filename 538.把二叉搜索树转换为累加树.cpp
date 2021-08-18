/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        int pre = 0;
        inOrder(root, pre);
        return root;
    }

    void inOrder(TreeNode* root, int& pre) {
        if (!root) return;
        inOrder(root->right, pre);
        root->val = root->val + pre;
        pre = root->val;
        inOrder(root->left, pre);
    }
};
// @lc code=end
