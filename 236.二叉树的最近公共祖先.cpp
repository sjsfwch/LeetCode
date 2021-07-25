/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */
#include "headers.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto tmp = make_pair(0, root);
        search(root, p, q, 0, tmp);
        return tmp.second;
    }
    int search(TreeNode* root, TreeNode* p, TreeNode* q, int height,
               pair<int, TreeNode*>& res) {
        if (!root) return 0;
        int val = 0, left = 0, right = 0;
        if (root == p || root == q) val = 1;
        left = search(root->left, p, q, height + 1, res);
        right = search(root->right, p, q, height + 1, res);
        val += left + right;
        if (val == 2) {
            if (res.first < height) {
                res.first = height;
                res.second = root;
            }
        }
        return val;
    }
};
// @lc code=end
