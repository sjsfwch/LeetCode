/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

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
#include "headers.h"
// @lc code=start

class Solution {
   public:
    bool isValidBST(TreeNode* root) {
        vector<int> order;
        return inOrder(root, order);
    }
    bool inOrder(TreeNode* root, vector<int>& order) {
        if (!root) return true;
        bool left = inOrder(root->left, order);
        if (!left) return false;
        if (!order.empty() && order.back() >= root->val) return false;
        order.push_back(root->val);
        bool right = inOrder(root->right, order);
        return right;
    }
};
// @lc code=end
