/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<vector<int>> res;
        dfs(nums, cur, res, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& cur, vector<vector<int>>& res,
             int start) {
        res.push_back(cur);
        if (start >= nums.size()) return;
        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, cur, res, i + 1);
            cur.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
    }
};
// @lc code=end
