/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int buy = INT32_MAX, res = 0;
        for (auto& price : prices) {
            if (price < buy)
                buy = price;
            else
                res = max(res, price - buy);
        }
        return res;
    }
};
// @lc code=end
