/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include "headers.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> choose;
        dfs(n, k, k, res, choose);
        return res;
    }
    void dfs(int n, int k, int need, vector<vector<int>>& res,
             vector<int>& choose) {
        if (need == 0) {
            if (choose.size() == k) res.push_back(choose);

            return;
        }
        int start = 0;
        if (choose.empty())
            start = 1;
        else
            start = *choose.rbegin() + 1;
        while (start <= n) {
            choose.push_back(start);
            dfs(n, k, need - 1, res, choose);
            choose.pop_back();
            start++;
        }
    }
};
// @lc code=end

int main() {
    Solution t;
    t.combine(4, 2);
    return 0;
}