/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(Max, Max);
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// @lc code=end

int main() {
    vector<int> x = {411, 412, 413, 414, 415, 416,
                     417, 418, 419, 420, 421, 422};
    Solution t;
    t.coinChange(x, 9864);
}