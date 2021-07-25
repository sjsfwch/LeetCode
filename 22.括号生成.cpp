/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include "headers.h"

// @lc code=start
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        DFS(0, 0, n, cur, res);
        return res;
    }
    void DFS(int left, int right, int n, string cur, vector<string>& res) {
        if (left == right && right == n) {
            res.push_back(cur);
            return;
        }
        if (left < right) return;
        if (left < n) {
            // cur += "(";
            DFS(left + 1, right, n, cur + '(', res);
        }
        // cur.pop_back();
        if (right < left && left <= n) {
            // cur += ")";
            DFS(left, right + 1, n, cur + ')', res);
        }
        // cur.pop_back();
    }
};
// @lc code=end

int main() {
    Solution t;
    t.generateParenthesis(1);
    return 0;
}