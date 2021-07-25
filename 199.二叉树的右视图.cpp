/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<pair<TreeNode*, int>> visit;
        visit.push(make_pair(root, 0));
        while (!visit.empty()) {
            auto node = visit.front();
            visit.pop();
            if (res.size() <= node.second)
                res.push_back(node.first->val);
            else {
                res[node.second] = node.first->val;
            }
            if (node.first->left)
                visit.push(make_pair(node.first->left, node.second + 1));
            if (node.first->right)
                visit.push(make_pair(node.first->right, node.second + 1));
        }
        return res;
    }
};
// @lc code=end
