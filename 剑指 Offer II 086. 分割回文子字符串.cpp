#include "headers.h"

class Solution {
   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        dfs(s, res, 0, cur);
        return res;
    }
    bool isValid(string s, int lo, int hi) {
        if (lo >= s.size()) return false;
        while (lo < hi) {
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }
    void dfs(string s, vector<vector<string>>& res, int start,
             vector<string>& cur) {
        if (start >= s.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (isValid(s, start, i)) {
                cur.push_back(s.substr(start, i - start + 1));
                dfs(s, res, i + 1, cur);
                cur.pop_back();
            }
        }
    }
};