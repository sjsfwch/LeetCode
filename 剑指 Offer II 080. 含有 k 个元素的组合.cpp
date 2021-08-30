#include "headers.h"

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(n, 1, k, cur, res);
        return res;
    }
    void dfs(int n, int start, int k, vector<int>& cur,
             vector<vector<int>>& res) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        if (start > n) return;
        for (int i = start; i <= n; ++i) {
            cur.push_back(i);
            dfs(n, i + 1, k, cur, res);
            cur.pop_back();
        }
    }
};