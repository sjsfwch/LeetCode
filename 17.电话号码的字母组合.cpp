/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
   public:
    string d2s[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string tmp = "";
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        DFS(digits, 0);
        return res;
    }
    void DFS(string& digits, int cursor) {
        if (cursor == digits.size()) {
            res.push_back(tmp);
            return;
        }
        for (auto c : d2s[digits[cursor] - '0' - 2]) {
            tmp.push_back(c);
            DFS(digits, cursor + 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end
