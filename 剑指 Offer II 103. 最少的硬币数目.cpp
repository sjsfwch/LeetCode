#include "headers.h"

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        // memset(dp, 1, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            dp[i] = amount + 1;
            for (auto coin : coins) {
                if (i >= coin) dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    Solution t;
    t.coinChange(coins, 11);
    return 0;
}