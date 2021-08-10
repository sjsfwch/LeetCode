/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    vector<string> removeInvalidParentheses(string s) {
        auto deletePa = calDeleteNum(s);
        vector<string> res;
        dfs(s, res, 0, deletePa.first, deletePa.second, 0, 0);
        return res;
    }
    pair<int, int> calDeleteNum(string s) {
        int left = 0, right = 0;
        for (auto c : s) {
            if (c == '(')
                left++;
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }
        return make_pair(left, right);
    }

    bool isValid(string s, int start, int left, int right) {
        while (start < s.size()) {
            if (s[start] == '(')
                left++;
            else if (s[start] == ')')
                right++;
            if (left < right) return false;
            start++;
        }
        return left == right;
    }

    void dfs(string s, vector<string>& res, int start, int left, int right,
             int nowLeft, int nowRight) {
        if (left == right && left == 0) {
            if (isValid(s, start, nowLeft, nowRight)) res.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (nowLeft < nowRight) return;
            if (s[i] == '(') {
                if (left > 0) {
                    dfs(string(s).erase(i, 1), res, i, left - 1, right, nowLeft,
                        nowRight);
                    while (i + 1 < s.size() && s[i + 1] == s[i]) {
                        i++;
                        nowLeft++;
                    }
                }
                nowLeft++;
            } else if (s[i] == ')') {
                if (right > 0) {
                    dfs(string(s).erase(i, 1), res, i, left, right - 1, nowLeft,
                        nowRight);
                    while (i + 1 < s.size() && s[i + 1] == s[i]) {
                        i++;
                        nowRight++;
                    }
                }
                nowRight++;
            }
        }
    }
};
// @lc code=end

int main() {
    Solution t;
    string s = "123456";
    // cout << s.erase(0, 0);
    t.removeInvalidParentheses("(()))e())()");
    return 0;
}