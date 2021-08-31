#include "headers.h"

class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, cur, res, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, vector<int>& cur,
             vector<vector<int>>& res, int start) {
        if (target == 0) {
            res.push_back(cur);
            return;
        } else if (target < 0)
            return;
        for (int i = start; i < candidates.size(); ++i) {
            while (i > start && i < candidates.size() &&
                   candidates[i] == candidates[i - 1])
                ++i;
            if (i >= candidates.size()) break;
            if (target < candidates[i]) break;
            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], cur, res, i + 1);
            cur.pop_back();
        }
    }
};