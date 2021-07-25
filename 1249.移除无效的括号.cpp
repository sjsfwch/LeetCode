/*
 * @lc app=leetcode.cn id=1249 lang=cpp
 *
 * [1249] 移除无效的括号
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    string minRemoveToMakeValid(string s) {
        stack<int> tmp;
        vector<int> need_delete;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                tmp.push(i);
            else if (s[i] == ')') {
                if (tmp.empty())
                    need_delete.push_back(i);
                else
                    tmp.pop();
            }
        }
        while (!tmp.empty()) {
            need_delete.push_back(tmp.top());
            tmp.pop();
        }
        sort(need_delete.begin(), need_delete.end());
        int i = 0, j = 0;
        string res;
        while (i < s.size()) {
            if (j >= need_delete.size())
                res += s[i];
            else if (i == need_delete[j])
                j++;

            else
                res += s[i];
            i++;
        }
        return res;
    }
};
// @lc code=end
