/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int countDigitOne(int n) {
        int res = 0;
        int high = n, cur = 0, lo = 0;
        long num = 1;
        while (high != 0 || cur != 0) {
            cur = high % 10;
            high /= 10;
            if (cur == 0)
                res += high * num;
            else if (cur == 1)
                res += high * num + 1 + lo;
            else
                res += high * num + num;
            lo = cur * num + lo;
            num *= 10;
        }
        return res;
    }
};
// @lc code=end
