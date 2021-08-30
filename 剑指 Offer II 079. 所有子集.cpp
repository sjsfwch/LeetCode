#include "headers.h"

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        res.push_back(cur);
        dfs(nums, 0, cur, res);
        return res;
    }
    void dfs(vector<int>& nums, int start, vector<int>& cur,
             vector<vector<int>>& res) {
        if (start >= nums.size()) return;
        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            res.push_back(cur);
            dfs(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }
};