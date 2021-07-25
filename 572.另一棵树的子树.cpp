/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;
        if (root->val == subRoot->val)
            return isSame(root, subRoot) || isSubtree(root->left, subRoot) ||
                   isSubtree(root->right, subRoot);
        ;
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        if ((!root) && (!subRoot)) return true;
        if ((!root) || (!subRoot)) return false;

        if (root->val != subRoot->val) return false;
        return isSame(root->left, subRoot->left) &&
               isSame(root->right, subRoot->right);
    }
};
// @lc code=end
