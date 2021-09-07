/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int balancedStringSplit(string s) {
        int tmp[2] = {0, 0};
        int res = 0;
        for (auto &c : s) {
            if (c == 'L')
                tmp[0]++;
            else
                tmp[1]++;
            if (tmp[0] == tmp[1]) res++;
        }
        return res;
    }
};
// @lc code=end
