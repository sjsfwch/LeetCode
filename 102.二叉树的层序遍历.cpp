/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<pair<int, TreeNode*>> tmp;
        tmp.push(make_pair(0, root));
        while (!tmp.empty()) {
            auto node = tmp.front();
            tmp.pop();
            if (node.first == res.size()) res.push_back(vector<int>());
            res[node.first].push_back(node.second->val);
            if (node.second->left)
                tmp.push(make_pair(node.first + 1, node.second->left));
            if (node.second->right)
                tmp.push(make_pair(node.first + 1, node.second->right));
        }
        return res;
    }
};
// @lc code=end
