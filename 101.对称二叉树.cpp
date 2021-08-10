/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return reverseSame(root->left, root->right);
    }

    bool reverseSame(TreeNode* l, TreeNode* r) {
        if (l && r) {
            if (l->val != r->val)
                return false;
            else
                return reverseSame(l->left, r->right) &&
                       reverseSame(l->right, r->left);
        } else if (l || r)
            return false;
        else
            return true;
    }
};
// @lc code=end
