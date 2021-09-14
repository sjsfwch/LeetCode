/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins) {
            for (int i = 1; i <= amount; ++i) {
                if (i < coin) continue;
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

int main() {
    vector<int> a = {1, 2, 5};
    Solution t;
    t.change(5, a);
    return 0;
}