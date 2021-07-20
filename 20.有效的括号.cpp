/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        stack<char> tmp;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{')
                tmp.push(c);
            else if (c == ')') {
                if (tmp.empty() || tmp.top() != '(') return false;
                tmp.pop();
            } else if (c == ']') {
                if (tmp.empty() || tmp.top() != '[') return false;
                tmp.pop();
            } else if (c == '}') {
                if (tmp.empty() || tmp.top() != '{') return false;
                tmp.pop();
            }
        }
        return tmp.empty();
    }
};
// @lc code=end
