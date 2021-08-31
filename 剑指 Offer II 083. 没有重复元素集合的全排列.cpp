#include "headers.h"
// 此题还可以循环调用 next_permutation
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        vector<bool> visit(nums.size(), false);
        dfs(nums, cur, res, visit);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& cur, vector<vector<int>>& res,
             vector<bool>& visit) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visit[i]) continue;
            cur.push_back(nums[i]);
            visit[i] = true;
            dfs(nums, cur, res, visit);
            cur.pop_back();
            visit[i] = false;
        }
    }
};

class Solution1 {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};