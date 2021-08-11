/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> cur;
        if (!root) return res;
        dfs(root, res, cur, targetSum);
        return res;
    }
    void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& cur,
             int target) {
        cur.push_back(root->val);
        if ((!root->left) && (!root->right)) {
            if (target == root->val) res.push_back(cur);

        } else {
            if (root->left) dfs(root->left, res, cur, target - root->val);
            if (root->right) dfs(root->right, res, cur, target - root->val);
        }
        cur.pop_back();
    }
};
// @lc code=end
