/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> visit(nums.size(), false);
        DFS(nums, res, cur, visit);
        return res;
    }
    void DFS(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur,
             vector<bool>& visit) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visit[i]) continue;

            cur.push_back(nums[i]);
            visit[i] = true;
            DFS(nums, res, cur, visit);
            visit[i] = false;
            cur.pop_back();
        }
    }
};
// @lc code=end
